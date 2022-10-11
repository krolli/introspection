#pragma once
#include "introspection.hpp"

/*
    A
    |\
    B D
   /| |
  E C |
   \|/
    F
*/

struct A
{
    float f32;
};

struct B : virtual A
{
    unsigned char u8;
};

struct C : B
{
    int s32;
};

struct D : virtual A
{
    double f64;
};

struct E : B
{
    short s16;
};

struct F : C, D, E
{
    bool b8;
};

mel_SpecializeTypeOf(A)
mel_SpecializeTypeOf(B)
mel_SpecializeTypeOf(C)
mel_SpecializeTypeOf(D)
mel_SpecializeTypeOf(E)
mel_SpecializeTypeOf(F)
