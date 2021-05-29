#ifndef ONKIGENERICS_CONTAINER_FACTORY_H
#define ONKIGENERICS_CONTAINER_FACTORY_H
#include <cstddef>
#include <array>
#include <type_traits>
namespace onkigenerics {

template<typename Container>
struct ContainerFactory
{
    using value_type = typename Container::value_type;

    static Container create(std::size_t size)
    {
        return Container(size);
    }

    template<std::ptrdiff_t N, typename BaseContainer>
    static Container create_with_incremented_size(BaseContainer &&base)
    {
        return Container(static_cast<std::size_t>(static_cast<std::ptrdiff_t>(base.size()) + N));
    }
};
template<typename T, std::size_t N>
struct ContainerFactory<std::array<T, N>>
{
    using value_type = T;

    static std::array<T, N> create(std::size_t)
    {
        return {};
    }
    template<std::ptrdiff_t Difference, typename BaseContainer>
    static std::array<T, static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + Difference)> create_with_incremented_size(BaseContainer &&)
    {
        return {};
    }
};

template<typename T, std::size_t N>
struct ContainerFactory<T[N]>
{
    using value_type = T;

    static std::array<T, N> create(std::size_t)
    {
        return {};
    }

    template<std::ptrdiff_t Difference, typename BaseContainer>
    static std::array<T, static_cast<std::size_t>(static_cast<std::ptrdiff_t>(N) + Difference)> create_with_incremented_size(BaseContainer &&)
    {
        return {};
    }
};


}// namespace onkigenerics

#endif /* ONKIGENERICS_CONTAINER_FACTORY_H */
