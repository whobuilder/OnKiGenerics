#ifndef ONKIGENERICS_DEFAULT_DYNAMIC_CONTAINER_H
#define ONKIGENERICS_DEFAULT_DYNAMIC_CONTAINER_H
#include <OnKiGenerics/is_std_array.hpp>
#include <OnKiGenerics/remove_cvref.hpp>
#include <OnKiGenerics/container_factory.hpp>
#include <type_traits>
#include <vector>
namespace onkigenerics {
template<class Container>
using DefaultDynamicContainer = std::conditional_t<is_raw_or_std_array_v<remove_cvref_t<Container>>,
  std::vector<typename ContainerFactory<remove_cvref_t<Container>>::value_type>,
  remove_cvref_t<Container>>;
}

#endif /* ONKIGENERICS_DEFAULT_DYNAMIC_CONTAINER_H */
