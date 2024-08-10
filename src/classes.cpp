#include "classes.hpp"

static constexpr const Member Vector3_members[] = {
    mel_MakeMemberInfo(Vector3, float, x),
    mel_MakeMemberInfo(Vector3, float, y),
    mel_MakeMemberInfo(Vector3, float, z),
};
static constexpr const ClassType Vector3_type = {
    TypeCategory::Class, "Vector3", sizeof(Vector3), alignof(Vector3), {}, MakeSpan(Vector3_members),
};
mel_SpecializeTypeOfImpl_Class(Vector3)

DataIter A::GetDataIter()
{
    return DataIter{this, TypeOf<A>::value};
}
static constexpr const Member A_members[] = {
    mel_MakeMemberInfo(A, float, f32),
};
static constexpr const ClassType A_type = {
    TypeCategory::Class, "A", sizeof(A), alignof(A), {}, MakeSpan(A_members),
};
mel_SpecializeTypeOfImpl_Class(A)

DataIter B::GetDataIter()
{
    return DataIter{this, TypeOf<B>::value};
}
static constexpr const BaseType B_baseTypes[] = {
    mel_MakeBaseTypeInfo(B, A, BaseType::Virtual),
};
static constexpr const Member B_members[] = {
    mel_MakeMemberInfo(B, unsigned char, u8),
};
static constexpr const ClassType B_type = {
    TypeCategory::Class, "B", sizeof(B), alignof(B), MakeSpan(B_baseTypes), MakeSpan(B_members),
};
mel_SpecializeTypeOfImpl_Class(B)

DataIter C::GetDataIter()
{
    return DataIter{this, TypeOf<C>::value};
}
static constexpr const BaseType C_baseTypes[] = {
    mel_MakeBaseTypeInfo(C, B, BaseType::NoFlags),
};
static constexpr const Member C_members[] = {
    mel_MakeMemberInfo(C, int, s32),
};
static constexpr const ClassType C_type = {
    TypeCategory::Class, "C", sizeof(C), alignof(C), MakeSpan(C_baseTypes), MakeSpan(C_members),
};
mel_SpecializeTypeOfImpl_Class(C)

DataIter D::GetDataIter()
{
    return DataIter{this, TypeOf<D>::value};
}
static constexpr const BaseType D_baseTypes[] = {
    mel_MakeBaseTypeInfo(D, A, BaseType::Virtual),
};
static constexpr const Member D_members[] = {
    mel_MakeMemberInfo(D, double, f64),
};
static constexpr const ClassType D_type = {
    TypeCategory::Class, "D", sizeof(D), alignof(D), MakeSpan(D_baseTypes), MakeSpan(D_members),
};
mel_SpecializeTypeOfImpl_Class(D)

DataIter E::GetDataIter()
{
    return DataIter{this, TypeOf<E>::value};
}
static constexpr const BaseType E_baseTypes[] = {
    mel_MakeBaseTypeInfo(E, B, BaseType::NoFlags),
};
static constexpr const Member E_members[] = {
    mel_MakeMemberInfo(E, short, s16),
};
static constexpr const ClassType E_type = {
    TypeCategory::Class, "E", sizeof(E), alignof(E), MakeSpan(E_baseTypes), MakeSpan(E_members),
};
mel_SpecializeTypeOfImpl_Class(E)

DataIter F::GetDataIter()
{
    return DataIter{this, TypeOf<F>::value};
}
static constexpr const BaseType F_baseTypes[] = {
    mel_MakeBaseTypeInfo(F, C, BaseType::NoFlags),
    mel_MakeBaseTypeInfo(F, D, BaseType::NoFlags),
    mel_MakeBaseTypeInfo(F, E, BaseType::NoFlags),
};
static constexpr const Member F_members[] = {
    mel_MakeMemberInfo(F, bool, b8),
    mel_MakeMemberInfo(F, Vector3, pos),
    mel_MakeMemberInfo(F, int*, ps32),
    mel_MakeMemberInfo(F, int**, pps32),
};
static constexpr const ClassType F_type = {
    TypeCategory::Class, "F", sizeof(F), alignof(F), MakeSpan(F_baseTypes), MakeSpan(F_members),
};
mel_SpecializeTypeOfImpl_Class(F)
