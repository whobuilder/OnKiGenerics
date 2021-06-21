#ifndef ONKIGENERICS_DEFAULT_CONTAINER_H
#define ONKIGENERICS_DEFAULT_CONTAINER_H
#include <OnKiGenerics/container_factory.hpp>
#include <OnKiGenerics/remove_cvref.hpp>
#include <OnKiGenerics/is_std_array.hpp>
#include <OnKiGenerics/array_size.hpp>
#include <type_traits>
namespace onkigenerics {
template<typename Container>
struct default_container
{
    using base_container_t = onkigenerics::remove_cvref_t<Container>;
    using value_type = typename onkigenerics::ContainerFactory<Container>::value_type;
    using type = std::conditional_t<onkigenerics::is_raw_or_std_array_v<base_container_t>,
      std::array<value_type, onkigenerics::array_size<base_container_t>::value>,
      std::vector<value_type>>;
};

template<typename T>
using default_container_t = typename default_container<T>::type;
}// namespace onkigenerics
#endif /* ONKIGENERICS_DEFAULT_CONTAINER_H */
