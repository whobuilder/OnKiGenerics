#ifndef ONKIGENERICS_CREATE_ARRAY_H
#define ONKIGENERICS_CREATE_ARRAY_H
#include <array>
#include <utility>

// taken from stackoverflow and modified
// https://stackoverflow.com/questions/57756557/initializing-a-stdarray-with-a-constant-value
namespace onkigenerics {
namespace detail {
template<typename T, std::size_t... Is>
constexpr std::array<T, sizeof...(Is)>
  create_array(T value, std::index_sequence<Is...>)
{
    // cast Is to void to remove the warning: unused value
    return { (static_cast<void>(Is), value)... };
}

}// namespace detail

template<typename T, std::size_t N>
constexpr std::array<T, N> create_array(const T &value)
{
    return detail::create_array<T>(value, std::make_index_sequence<N>());
}
}// namespace onkigenerics

#endif /* ONKIGENERICS_CREATE_ARRAY_H */
