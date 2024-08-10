#pragma once
#include "introspection.hpp"

struct Vector3
{
    float x,y,z;
};

mel_SpecializeTypeOf_Class(Vector3)

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

    virtual DataIter GetDataIter();
};

struct B : virtual A
{
    unsigned char u8;

    DataIter GetDataIter() override;
};

struct C : B
{
    int s32;

    DataIter GetDataIter() override;
};

struct D : virtual A
{
    double f64;

    DataIter GetDataIter() override;
};

struct E : B
{
    short s16;

    DataIter GetDataIter() override;
};

struct F : C, D, E
{
    bool b8;
    Vector3 pos;
    int* ps32;
    int** pps32;

    DataIter GetDataIter() override;
};

mel_SpecializeTypeOf_Class(A)
mel_SpecializeTypeOf_Class(B)
mel_SpecializeTypeOf_Class(C)
mel_SpecializeTypeOf_Class(D)
mel_SpecializeTypeOf_Class(E)
mel_SpecializeTypeOf_Class(F)
