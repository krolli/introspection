#pragma once
#include <cstddef>

template<class T>
struct Span
{
    T* start;
    size_t length;

    T* begin() const { return this->start; }
    T* end() const { return this->start + this->length; }
};

template<class T, size_t length>
constexpr Span<T> MakeSpan(T (&data)[length])
{
    return {data, length};
}
