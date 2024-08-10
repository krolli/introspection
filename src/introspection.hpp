#pragma once
#include "span.hpp"

struct Type;
struct ClassType;

enum class TypeCategory : char
{
    Fundamental,
    Class,
};

struct BaseType
{
    enum Flags : unsigned char
    {
        NoFlags = 0,
        Virtual = 1 << 0,
    };

    using AccessFn = void* (void*);

    ClassType const* type;
    AccessFn* access;
    Flags flags;
};

struct Member
{
    using AccessFn = void* (void*);

    char const* name;
    Type const* type;
    AccessFn* access;
};

struct Type
{
    TypeCategory category;
    char const* name;
    size_t size;
    size_t alignment;
};

struct FundamentalType : Type
{
};

struct ClassType : Type
{
    Span<BaseType const> baseTypes;
    Span<Member const> members;
};

template<class T> struct TypeOf { };

struct DataIter
{
    void* data;
    Type const* type;

    DataIter AccessMember(Member const& member)
    {
        // assert(type && data);
        // assert(&member - type->members.start < type->members.length);
        return DataIter{member.access(this->data), member.type};
    }

    DataIter AccessBaseType(BaseType const& base)
    {
        // assert(type && data);
        // assert(&base - type->baseTypes.start < type->baseTypes.length);
        return DataIter{base.access(this->data), base.type};
    }
};

template<class T, class B>
void* InstanceToBase(void* selfAddr)
{
    T* self = static_cast<T*>(selfAddr);
    B* base = self;
    return base;
}

template<class T, class M, M T::*ptr>
void* InstanceToMember(void* selfAddr)
{
    T* self = static_cast<T*>(selfAddr);
    return &(self->*ptr);
}

#define mel_SpecializeTypeOf_(typeCategory, typeName) \
    template<> struct TypeOf<typeName> { static typeCategory const inst; static inline constexpr typeCategory const * const value = &inst; };

#define mel_SpecializeTypeOf_Fundamental(typeName) mel_SpecializeTypeOf_(FundamentalType, typeName)
#define mel_SpecializeTypeOf_Class(typeName) mel_SpecializeTypeOf_(ClassType, typeName)

#define mel_SpecializeTypeOfImpl_Class(typeName) \
    ClassType const TypeOf<typeName>::inst = typeName##_type;

#define mel_MakeMemberInfo(ownerType, memberType, memberName) \
    {#memberName, TypeOf<memberType>::value, InstanceToMember<ownerType, memberType, &ownerType::memberName>}

#define mel_MakeBaseTypeInfo(type, baseType, flags) \
    {TypeOf<baseType>::value, InstanceToBase<type, baseType>, BaseType::Flags(flags)}

mel_SpecializeTypeOf_Fundamental(bool)

mel_SpecializeTypeOf_Fundamental(char)
mel_SpecializeTypeOf_Fundamental(signed char)
mel_SpecializeTypeOf_Fundamental(unsigned char)

mel_SpecializeTypeOf_Fundamental(signed short int)
mel_SpecializeTypeOf_Fundamental(signed int)
mel_SpecializeTypeOf_Fundamental(signed long int)
mel_SpecializeTypeOf_Fundamental(signed long long int)
mel_SpecializeTypeOf_Fundamental(unsigned short int)
mel_SpecializeTypeOf_Fundamental(unsigned int)
mel_SpecializeTypeOf_Fundamental(unsigned long int)
mel_SpecializeTypeOf_Fundamental(unsigned long long int)

mel_SpecializeTypeOf_Fundamental(float)
mel_SpecializeTypeOf_Fundamental(double)
mel_SpecializeTypeOf_Fundamental(long double)
