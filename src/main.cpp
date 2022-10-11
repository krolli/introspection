#include "classes.hpp"
#include <cstddef>
#include <cstdio>

static constexpr const char INDENT[] = "                                                           ";

static void printMembers(void* inst, Type const* type, char const* indent)
{
    for (Member const& member : type->members)
    {
        printf("%s%s %s = ", indent, member.type->name, member.name);
        void* pMember = member.access(inst);
        if (member.type == TypeOf<bool>::value)
        {
            bool val = *(bool*)pMember;
            printf("%s(%u)", val ? "true" : "false", unsigned(val));
        }
        else if (member.type == TypeOf<char>::value)
        {
            printf("'%c'", *(char*)pMember);
        }
        else if (member.type == TypeOf<signed char>::value)
        {
            printf("'%c'", *(signed char*)pMember);
        }
        else if (member.type == TypeOf<unsigned char>::value)
        {
            printf("'%c'u", *(unsigned char*)pMember);
        }
        else if (member.type == TypeOf<short>::value)
        {
            printf("%d", *(short*)pMember);
        }
        else if (member.type == TypeOf<int>::value)
        {
            printf("%d", *(int*)pMember);
        }
        else if (member.type == TypeOf<float>::value)
        {
            printf("%f", *(float*)pMember);
        }
        else if (member.type == TypeOf<double>::value)
        {
            printf("%f", *(double*)pMember);
        }
        else
        {
            printf("???");
        }
        printf("\n");
    }
}

static void printTypeInfo_r(void* inst, Type const* type, const char* indent)
{
    for (BaseType const& baseType : type->baseTypes)
    {
        void* base = baseType.access(inst);
        printTypeInfo_r(base, baseType.type, indent);
    }
    printf("%s%p -> %s (size: %zu, alignment: %zu) {\n",
        indent, inst, type->name, type->size, type->alignment
    );
    indent -= 2;
    printMembers(inst, type, indent);
    indent += 2;
    printf("%s}\n", indent);
}

static void printTypeInfo(void* inst, Type const* type)
{
    const char* indent = &INDENT[sizeof(INDENT) - 1];
    printf("%s%p -> %s (size: %zu, alignment: %zu) {\n",
        indent, inst, type->name, type->size, type->alignment
    );
    indent -= 2;
    for (BaseType const& baseType : type->baseTypes)
    {
        void* base = baseType.access(inst);
        printTypeInfo_r(base, baseType.type, indent);
    }

    printMembers(inst, type, indent);
    indent += 2;
    printf("%s}\n", indent);
}

int main(int argc, char** argv)
{
    F var = {};
    var.f32 = 1.0f;
    static_cast<C&>(var).u8 = 'C';
    static_cast<E&>(var).u8 = 'E';
    var.s32 = 3;
    var.f64 = 2.0;
    var.s16 = 4;
    var.b8 = true;
    printTypeInfo(&var, TypeOf<F>::value);
    return 0;
}
