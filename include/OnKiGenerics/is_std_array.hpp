#ifndef ONKIGENERICS_IS_STD_ARRAY_H
#define ONKIGENERICS_IS_STD_ARRAY_H
#include <array>
#include <type_traits>
namespace onkigenerics {

template<class T>
struct is_std_array : std::false_type
{
};

template<class T, std::size_t N>
struct is_std_array<std::array<T, N>> : std::true_type
{
};

template<class T>
inline constexpr bool is_std_array_v = is_std_array<T>::value;

template<typename T>
struct is_raw_or_std_array : std::conditional_t<(std::is_array_v<T> || is_std_array_v<T>), std::true_type, std::false_type>
{
};

template<class T>
inline constexpr bool is_raw_or_std_array_v = is_raw_or_std_array<T>::value;

}// namespace onkigenerics

#endif /* ONKIGENERICS_IS_STD_ARRAY_H */
