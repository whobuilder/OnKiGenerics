#include <catch2/catch.hpp>
#include <OnKiGenerics/container_factory.hpp>
#include <OnKiGenerics/is_std_array.hpp>
#include <type_traits>
#include <array>
#include <deque>
#include <vector>
#include <list>

TEMPLATE_TEST_CASE("create standard containers with size", "[create]", std::vector<int>, std::deque<float>, std::list<long int>, (int[6]), (std::array<double, 6>))
{
    auto container = onkigenerics::ContainerFactory<TestType>::create(6);
    if constexpr (onkigenerics::is_raw_or_std_array_v<TestType>) {
        static_assert(std::size(container) == 6);
    }
    REQUIRE(std::size(container) == 6);
}

TEMPLATE_TEST_CASE("create standard containers with one less size rvalue input", "[create_with_incremented_size]", std::vector<int>, std::deque<float>, std::list<long int>, (int[6]), (std::array<double, 6>))
{
    auto container = onkigenerics::ContainerFactory<TestType>::create_with_incremented_size<-1>(std::vector<float>(6));
    if constexpr (onkigenerics::is_raw_or_std_array_v<TestType>) {
        static_assert(std::size(container) == 5);
    }
    REQUIRE(std::size(container) == 5);
}

TEMPLATE_TEST_CASE("create standard containers with two less size lvalue reference input", "[create_with_incremented_size]", std::vector<int>, std::deque<float>, std::list<long int>, (int[6]), (std::array<double, 6>))
{
    const auto &big_vec = std::vector<int>(6);
    auto container = onkigenerics::ContainerFactory<TestType>::create_with_incremented_size<-2>(big_vec);
    if constexpr (onkigenerics::is_raw_or_std_array_v<TestType>) {
        static_assert(std::size(container) == 4);
    }
    REQUIRE(std::size(container) == 4);
}
