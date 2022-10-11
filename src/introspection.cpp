#include "introspection.hpp"

#define mel_SpecializeTypeOfImpl_Primitive(typeName, valName) \
    static constexpr const Type valName = {#typeName, sizeof(typeName), alignof(typeName), {}, {}}; \
    Type const* const TypeOf<typeName>::value = &valName;

mel_SpecializeTypeOfImpl_Primitive(bool, bool_type)

mel_SpecializeTypeOfImpl_Primitive(char, c_type)
mel_SpecializeTypeOfImpl_Primitive(signed char, sc_type)
mel_SpecializeTypeOfImpl_Primitive(unsigned char, uc_type)

mel_SpecializeTypeOfImpl_Primitive(signed short int, ssi_type)
mel_SpecializeTypeOfImpl_Primitive(signed int, si_type)
mel_SpecializeTypeOfImpl_Primitive(signed long int, sli_type)
mel_SpecializeTypeOfImpl_Primitive(signed long long int, slli_type)
mel_SpecializeTypeOfImpl_Primitive(unsigned short int, usi_type)
mel_SpecializeTypeOfImpl_Primitive(unsigned int, ui_type)
mel_SpecializeTypeOfImpl_Primitive(unsigned long int, uli_type)
mel_SpecializeTypeOfImpl_Primitive(unsigned long long int, ulli_type)

mel_SpecializeTypeOfImpl_Primitive(float, float_type)
mel_SpecializeTypeOfImpl_Primitive(double, double_type)
mel_SpecializeTypeOfImpl_Primitive(long double, ldouble_type)
