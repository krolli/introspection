#include "introspection.hpp"

#define mel_SpecializeTypeOfImpl_Fundamental(typeName, valName) \
    static constexpr const FundamentalType valName = {TypeCategory::Fundamental, #typeName, sizeof(typeName), alignof(typeName)}; \
    FundamentalType const TypeOf<typeName>::inst = valName;

mel_SpecializeTypeOfImpl_Fundamental(bool, bool_type)

mel_SpecializeTypeOfImpl_Fundamental(char, c_type)
mel_SpecializeTypeOfImpl_Fundamental(signed char, sc_type)
mel_SpecializeTypeOfImpl_Fundamental(unsigned char, uc_type)

mel_SpecializeTypeOfImpl_Fundamental(signed short int, ssi_type)
mel_SpecializeTypeOfImpl_Fundamental(signed int, si_type)
mel_SpecializeTypeOfImpl_Fundamental(signed long int, sli_type)
mel_SpecializeTypeOfImpl_Fundamental(signed long long int, slli_type)
mel_SpecializeTypeOfImpl_Fundamental(unsigned short int, usi_type)
mel_SpecializeTypeOfImpl_Fundamental(unsigned int, ui_type)
mel_SpecializeTypeOfImpl_Fundamental(unsigned long int, uli_type)
mel_SpecializeTypeOfImpl_Fundamental(unsigned long long int, ulli_type)

mel_SpecializeTypeOfImpl_Fundamental(float, float_type)
mel_SpecializeTypeOfImpl_Fundamental(double, double_type)
mel_SpecializeTypeOfImpl_Fundamental(long double, ldouble_type)
