#include <catch2/catch.hpp>
#include <OnKiGenerics/default_dynamic_container.hpp>
#include <list>
TEST_CASE("default dynamic container with std::array input test", "[default_dynamic_contaienr]")
{
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<const std::array<int, 42> &>, std::vector<int>>);
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<const std::array<int, 121>>, std::vector<int>>);
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<std::array<int, 8>>, std::vector<int>>);
}

TEST_CASE("default dynamic container with raw array input test", "[default_dynamic_contaienr]")
{
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<const int(&)[42]>, std::vector<int>>);
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<const int[121]>, std::vector<int>>);
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<int[121]>, std::vector<int>>);
}

TEST_CASE("default dynamic container with dynamic container input test", "[default_dynamic_contaienr]")
{
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<const std::list<int> &>, std::list<int>>);
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<const std::list<int>>, std::list<int>>);
    REQUIRE(std::is_same_v<onkigenerics::DefaultDynamicContainer<std::list<int>>, std::list<int>>);
}
