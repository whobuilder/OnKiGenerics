#ifndef ONKIGENERICS_INCREMENTED_TYPE_H
#define ONKIGENERICS_INCREMENTED_TYPE_H
#include <cstddef>
#include <array>
namespace onkigenerics {
template<class T, std::ptrdiff_t D>
class incremented
{
public:
    using type = T;
};

template<class T, std::size_t N, std::ptrdiff_t D>
class incremented<std::array<T, N>, D>
{
public:
    using type = std::array<T, static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + D)>;
};

template<class T, std::size_t N, std::ptrdiff_t D>
class incremented<T[N], D>
{
public:
    using type = T[static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + D)];
};

template<class T, std::ptrdiff_t D>
using incremented_t = typename incremented<T, D>::type;
}// namespace onkigenerics

#endif /* ONKIGENERICS_INCREMENTED_TYPE_H */
