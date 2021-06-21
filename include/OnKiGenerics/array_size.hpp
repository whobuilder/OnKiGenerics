#ifndef ONKIGENERICS_ARRAY_SIZE_H
#define ONKIGENERICS_ARRAY_SIZE_H
#include <type_traits>
#include <array>
namespace onkigenerics {
template<class T>
struct array_size : std::integral_constant<std::size_t, 0>
{
};

template<class T, std::size_t N>
struct array_size<std::array<T, N>> : std::integral_constant<std::size_t, N>
{
};

template<class T, std::size_t N>
struct array_size<T[N]> : std::integral_constant<std::size_t, N>
{
};
}// namespace onkigenerics

#endif /* ONKIGENERICS_ARRAY_SIZE_H */
