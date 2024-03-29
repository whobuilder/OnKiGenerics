#ifndef ONKIGENERICS_CONTAINER_FACTORY_H
#define ONKIGENERICS_CONTAINER_FACTORY_H
#include <cstddef>
#include <array>
#include <type_traits>
#include <OnKiGenerics/create_array.hpp>
#include <OnKiGenerics/remove_cvref.hpp>
#include <OnKiGenerics/incremented_type.hpp>
namespace onkigenerics {

template<typename Container>
struct ContainerFactory
{
    using value_type = std::remove_pointer_t<onkigenerics::remove_cvref_t<typename std::remove_pointer_t<onkigenerics::remove_cvref_t<Container>>::value_type>>;

    static Container create(std::size_t size, value_type initial_value = value_type{})
    {
        return Container(size, initial_value);
    }

    template<std::ptrdiff_t N, typename BaseContainer>
    static incremented_t<Container, N> create_with_incremented_size(BaseContainer &&base, value_type initial_value = value_type{})
    {
        return incremented_t<Container, N>(static_cast<std::size_t>(static_cast<std::ptrdiff_t>(base.size()) + N), initial_value);
    }
};
template<typename T, std::size_t N>
struct ContainerFactory<std::array<T, N>>
{
    using value_type = std::remove_pointer_t<onkigenerics::remove_cvref_t<T>>;

    static std::array<T, N> create(std::size_t, value_type initial_value = value_type{})
    {
        return create_array<value_type, N>(initial_value);
    }
    template<std::ptrdiff_t Difference, typename BaseContainer>
    static incremented_t<std::array<T, N>, Difference> create_with_incremented_size(BaseContainer &&, value_type initial_value = value_type{})
    {
        return create_array<value_type, static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + Difference)>(initial_value);
    }
};

template<typename T, std::size_t N>
struct ContainerFactory<T[N]>
{
    using value_type = std::remove_pointer_t<onkigenerics::remove_cvref_t<T>>;

    static std::array<value_type, N> create(std::size_t, value_type initial_value = value_type{})
    {
        return create_array<value_type, N>(initial_value);
    }

    template<std::ptrdiff_t Difference, typename BaseContainer>
    static std::array<T, static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + Difference)> create_with_incremented_size(BaseContainer &&, value_type initial_value = value_type{})
    {
        return create_array<value_type, static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + Difference)>(initial_value);
    }
};

template<typename T, std::size_t N>
struct ContainerFactory<T (&)[N]>
{
    using value_type = std::remove_pointer_t<onkigenerics::remove_cvref_t<T>>;

    static std::array<value_type, N> create(std::size_t, value_type initial_value = value_type{})
    {
        return create_array<value_type, N>(initial_value);
    }

    template<std::ptrdiff_t Difference, typename BaseContainer>
    static std::array<T, static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + Difference)> create_with_incremented_size(BaseContainer &&, value_type initial_value = value_type{})
    {
        return create_array<value_type, static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + Difference)>(initial_value);
    }
};


}// namespace onkigenerics

#endif /* ONKIGENERICS_CONTAINER_FACTORY_H */
