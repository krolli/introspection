#pragma once
#include "span.hpp"

struct Type;

struct BaseType
{
    using AccessFn = void* (void*);

    Type const* type;
    AccessFn* access;
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
    char const* name;
    size_t size;
    size_t alignment;
    Span<BaseType const> baseTypes;
    Span<Member const> members;
};

template<class T> struct TypeOf { };

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

#define mel_SpecializeTypeOf(typeName) \
    template<> struct TypeOf<typeName> { static Type const* const value; };

#define mel_SpecializeTypeOfImpl(typeName) \
    Type const* const TypeOf<typeName>::value = &typeName##_type;

#define mel_MakeMemberInfo(ownerType, memberType, memberName) \
    {#memberName, TypeOf<memberType>::value, InstanceToMember<ownerType, memberType, &ownerType::memberName>}

#define mel_MakeBaseTypeInfo(type, baseType) \
    {TypeOf<baseType>::value, InstanceToBase<type, baseType>}

mel_SpecializeTypeOf(bool)

mel_SpecializeTypeOf(char)
mel_SpecializeTypeOf(signed char)
mel_SpecializeTypeOf(unsigned char)

mel_SpecializeTypeOf(signed short int)
mel_SpecializeTypeOf(signed int)
mel_SpecializeTypeOf(signed long int)
mel_SpecializeTypeOf(signed long long int)
mel_SpecializeTypeOf(unsigned short int)
mel_SpecializeTypeOf(unsigned int)
mel_SpecializeTypeOf(unsigned long int)
mel_SpecializeTypeOf(unsigned long long int)

mel_SpecializeTypeOf(float)
mel_SpecializeTypeOf(double)
mel_SpecializeTypeOf(long double)
