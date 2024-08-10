#include "classes.hpp"
#include <cstddef>
#include <cstdio>
#include <vector>
#include <cstdint>

static constexpr const char INDENT[] = "                                                           ";

void printData_r(DataIter it, const char* indent);

static void printFundamental(FundamentalType const* type, void* data, char const* indent)
{
    if (type == TypeOf<bool>::value)
    {
        bool val = *(bool*)data;
        printf("%s(%u)", val ? "true" : "false", unsigned(val));
    }
    else if (type == TypeOf<char>::value)
    {
        printf("'%c'", *(char*)data);
    }
    else if (type == TypeOf<signed char>::value)
    {
        printf("'%c'", *(signed char*)data);
    }
    else if (type == TypeOf<unsigned char>::value)
    {
        printf("'%c'u", *(unsigned char*)data);
    }
    else if (type == TypeOf<short>::value)
    {
        printf("%d", *(short*)data);
    }
    else if (type == TypeOf<int>::value)
    {
        printf("%d", *(int*)data);
    }
    else if (type == TypeOf<float>::value)
    {
        printf("%f", *(float*)data);
    }
    else if (type == TypeOf<double>::value)
    {
        printf("%f", *(double*)data);
    }
    else
    {
        printf("???");
    }
}

static void printPointer(PointerType const* type, void* data, char const* indent)
{
    void* val = type->access(data);
    printf("0x%016X", uintptr_t(val));
    if (val)
    {
        printf(" -> ");
        printData_r(DataIter{val, type->pointeeType}, indent);
    }
}

static void printMembers(ClassType const* type, void* data, char const* indent)
{
    for (Member const& member : type->members)
    {
        printf("%s%s %s = ", indent, member.type->name, member.name);
        printData_r(DataIter{member.access(data), member.type}, indent);
        printf("\n");
    }
}

static void addVirtualBase(std::vector<DataIter>* virtualBases, ClassType const* type, void* data)
{
    for (const DataIter& virtualBase : *virtualBases)
    {
        if (virtualBase.type == type && virtualBase.data == data)
            return;
    }

    virtualBases->push_back(DataIter{data, type});
}

static void printBaseClass(std::vector<DataIter>* virtualBases, ClassType const* type, void* data, const char* indent)
{
    for (BaseType const& baseType : type->baseTypes)
    {
        if (baseType.flags & BaseType::Virtual)
            addVirtualBase(virtualBases, baseType.type, baseType.access(data));
        else
            printBaseClass(virtualBases, baseType.type, baseType.access(data), indent);
    }
    printf("%s%p -> %s (size: %zu, alignment: %zu) {\n",
        indent, data, type->name, type->size, type->alignment
    );
    indent -= 2;
    printMembers(type, data, indent);
    indent += 2;
    printf("%s}\n", indent);
}

static void printClass(ClassType const* type, void* data, const char* indent)
{
    std::vector<DataIter> virtualBases;
    printf("%p -> %s (size: %zu, alignment: %zu) {\n",
        data, type->name, type->size, type->alignment
    );
    indent -= 2;
    for (BaseType const& baseType : type->baseTypes)
    {
        if (baseType.flags & BaseType::Virtual)
            addVirtualBase(&virtualBases, baseType.type, baseType.access(data));
        else
            printBaseClass(&virtualBases, baseType.type, baseType.access(data), indent);
    }

    for (size_t i = 0; i < virtualBases.size(); i++)
    {
        printBaseClass(
            &virtualBases,
            static_cast<ClassType const*>(virtualBases[i].type),
            virtualBases[i].data,
            indent
        );
    }

    printMembers(type, data, indent);
    indent += 2;
    printf("%s}", indent);
}

void printData_r(DataIter it, const char* indent)
{
    switch (it.type->category)
    {
        case TypeCategory::Fundamental:
            printFundamental(static_cast<FundamentalType const*>(it.type), it.data, indent);
            break;
        case TypeCategory::Pointer:
            printPointer(static_cast<PointerType const*>(it.type), it.data, indent);
            break;
        case TypeCategory::Class:
            printClass(static_cast<ClassType const*>(it.type), it.data, indent);
            break;
        default:
            printf("type?");
            break;
    }
}

static void printData(DataIter it)
{
    const char* indent = &INDENT[sizeof(INDENT) - 1];
    printData_r(it, indent);
    printf("\n");
}

void process(A* var)
{
    DataIter it = var->GetDataIter();
    printData(it);
}

int main(int argc, char** argv)
{
    int a = 10;
    F var = {};
    var.f32 = 1.0f;
    static_cast<C&>(var).u8 = 'C';
    static_cast<E&>(var).u8 = 'E';
    var.s32 = 3;
    var.f64 = 2.0;
    var.s16 = 4;
    var.b8 = true;
    var.pos.x = 125.0;
    var.pos.y = 75.5;
    var.pos.z = -109;
    var.ps32 = &a;
    var.pps32 = &var.ps32;
    process(&var);
    return 0;
}
