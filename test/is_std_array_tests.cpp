#include <catch2/catch.hpp>
#include <OnKiGenerics/is_std_array.hpp>

TEST_CASE("is_std_array test", "[is_std_array]")
{
    std::array<double, 5> arr;
    std::vector<double> vec;
    REQUIRE(onkigenerics::is_std_array_v<decltype(arr)>);
    REQUIRE_FALSE(onkigenerics::is_std_array_v<decltype(vec)>);
}

TEST_CASE("is_raw_or_std_array test", "[is_raw_or_std_array]")
{
    std::array<double, 5> arr;
    int carr[6];
    std::vector<double> vec;
    REQUIRE(onkigenerics::is_raw_or_std_array_v<decltype(arr)>);
    REQUIRE(onkigenerics::is_raw_or_std_array_v<decltype(carr)>);
    REQUIRE_FALSE(onkigenerics::is_raw_or_std_array_v<decltype(vec)>);
}
