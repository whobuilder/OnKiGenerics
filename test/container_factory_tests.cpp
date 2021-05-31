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
    auto container = onkigenerics::ContainerFactory<TestType>::template create_with_incremented_size<-1>(std::vector<float>(6));
    if constexpr (onkigenerics::is_raw_or_std_array_v<TestType>) {
        static_assert(std::size(container) == 5);
    }
    REQUIRE(std::size(container) == 5);
}

TEMPLATE_TEST_CASE("create standard containers with two less size lvalue reference input", "[create_with_incremented_size]", std::vector<int>, std::deque<float>, std::list<long int>, (int[6]), (std::array<double, 6>))
{
    const auto &big_vec = std::vector<int>(6);
    auto container = onkigenerics::ContainerFactory<TestType>::template create_with_incremented_size<-2>(big_vec);
    if constexpr (onkigenerics::is_raw_or_std_array_v<TestType>) {
        static_assert(std::size(container) == 4);
    }
    REQUIRE(std::size(container) == 4);
}

TEMPLATE_TEST_CASE("create standard containers with size using a custom value", "[create]", std::vector<int>, std::deque<float>, std::list<long int>, (int[6]), (std::array<double, 6>))
{
    using ValueType = typename onkigenerics::ContainerFactory<TestType>::value_type;
    constexpr ValueType initial_value = 42;
    constexpr std::size_t container_size = 6;
    auto container = onkigenerics::ContainerFactory<TestType>::create(container_size, initial_value);
    if constexpr (onkigenerics::is_raw_or_std_array_v<TestType>) {
        static_assert(std::size(container) == container_size);
    }
    REQUIRE(std::all_of(std::begin(container), std::end(container), [initial_value](const auto &value) { return value == initial_value; }));
}

TEMPLATE_TEST_CASE("create standard containers with one less size rvalue input using a custom value", "[create_with_incremented_size]", std::vector<int>, std::deque<float>, std::list<long int>, (int[6]), (std::array<double, 6>))
{
    using ValueType = typename onkigenerics::ContainerFactory<TestType>::value_type;
    constexpr ValueType initial_value = 42;
    constexpr std::size_t container_size = 6;
    constexpr int increment_size = -1;
    constexpr std::size_t new_size = container_size + static_cast<std::size_t>(increment_size);
    auto container = onkigenerics::ContainerFactory<TestType>::template create_with_incremented_size<increment_size>(std::vector<float>(container_size), initial_value);
    if constexpr (onkigenerics::is_raw_or_std_array_v<TestType>) {
        static_assert(std::size(container) == new_size);
    }
    REQUIRE(new_size==std::size(container));
    REQUIRE(std::all_of(std::begin(container), std::end(container), [initial_value](const auto &value) { return value == initial_value; }));
}

TEMPLATE_TEST_CASE("create standard containers with two less size lvalue reference input using a custom value", "[create_with_incremented_size]", std::vector<int>, std::deque<float>, std::list<long int>, (int[6]), (std::array<double, 6>))
{
    using ValueType = typename onkigenerics::ContainerFactory<TestType>::value_type;
    constexpr ValueType initial_value = 42;
    constexpr std::size_t container_size = 6;
    constexpr int increment_size = -2;
    constexpr auto new_size = container_size + static_cast<std::size_t>(increment_size);
    const auto &big_vec = std::vector<int>(container_size);
    auto container = onkigenerics::ContainerFactory<TestType>::template create_with_incremented_size<increment_size>(big_vec, initial_value);
    if constexpr (onkigenerics::is_raw_or_std_array_v<TestType>) {
        static_assert(std::size(container) == new_size);
    }
    REQUIRE(new_size==std::size(container));
    REQUIRE(std::all_of(std::begin(container), std::end(container), [initial_value](const auto &value) { return value == initial_value; }));
}