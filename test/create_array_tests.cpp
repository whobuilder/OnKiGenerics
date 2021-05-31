#include <catch2/catch.hpp>
#include <OnKiGenerics/create_array.hpp>
#include <algorithm>

TEST_CASE("create compile time array", "[create_array]")
{
    constexpr int initial_value = 5;
    constexpr auto arr = onkigenerics::create_array<const int, 3>(initial_value);
    REQUIRE(std::is_same_v<decltype(arr), const std::array<const int, 3>>);
    REQUIRE(std::all_of(begin(arr), end(arr), [initial_value](auto value) { return value == initial_value; }));
}