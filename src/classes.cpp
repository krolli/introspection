#include "classes.hpp"

static const Member A_members[] = {
    mel_MakeMemberInfo(A, float, f32),
};
static constexpr const Type A_type = {
    "A", sizeof(A), alignof(A), {}, MakeSpan(A_members),
};
mel_SpecializeTypeOfImpl(A)

static const BaseType B_baseTypes[] = {
    mel_MakeBaseTypeInfo(B, A),
};
static const Member B_members[] = {
    mel_MakeMemberInfo(B, unsigned char, u8),
};
static constexpr const Type B_type = {
    "B", sizeof(B), alignof(B), MakeSpan(B_baseTypes), MakeSpan(B_members),
};
mel_SpecializeTypeOfImpl(B)

static const BaseType C_baseTypes[] = {
    mel_MakeBaseTypeInfo(C, B),
};
static const Member C_members[] = {
    mel_MakeMemberInfo(C, int, s32),
};
static constexpr const Type C_type = {
    "C", sizeof(C), alignof(C), MakeSpan(C_baseTypes), MakeSpan(C_members),
};
mel_SpecializeTypeOfImpl(C)

static const BaseType D_baseTypes[] = {
    mel_MakeBaseTypeInfo(D, A),
};
static const Member D_members[] = {
    mel_MakeMemberInfo(D, double, f64),
};
static constexpr const Type D_type = {
    "D", sizeof(D), alignof(D), MakeSpan(D_baseTypes), MakeSpan(D_members),
};
mel_SpecializeTypeOfImpl(D)

static const BaseType E_baseTypes[] = {
    mel_MakeBaseTypeInfo(E, B),
};
static const Member E_members[] = {
    mel_MakeMemberInfo(E, short, s16),
};
static constexpr const Type E_type = {
    "E", sizeof(E), alignof(E), MakeSpan(E_baseTypes), MakeSpan(E_members),
};
mel_SpecializeTypeOfImpl(E)

static const BaseType F_baseTypes[] = {
    mel_MakeBaseTypeInfo(F, C),
    mel_MakeBaseTypeInfo(F, D),
    mel_MakeBaseTypeInfo(F, E),
};
static const Member F_members[] = {
    mel_MakeMemberInfo(F, bool, b8),
};
static constexpr const Type F_type = {
    "F", sizeof(F), alignof(F), MakeSpan(F_baseTypes), MakeSpan(F_members),
};
mel_SpecializeTypeOfImpl(F)
