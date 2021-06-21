#include <catch2/catch.hpp>
#include <OnKiGenerics/default_container.hpp>
#include <list>
#include <array>
TEST_CASE("default container with std::array input test", "[default_container]")
{
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<const std::array<int, 42> &>, std::array<int, 42>>);
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<const std::array<int, 121>>, std::array<int, 121>>);
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<std::array<int, 8>>, std::array<int, 8>>);
}

TEST_CASE("default  container with raw array input test", "[default_container]")
{
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<const int(&)[42]>, std::array<int, 42>>);
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<const int[121]>, std::array<int, 121>>);
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<int[121]>, std::array<int, 121>>);
}

TEST_CASE("default  container with dynamic container input test", "[default_contaienr]")
{
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<const std::list<int> &>, std::vector<int>>);
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<const std::list<int>>, std::vector<int>>);
    REQUIRE(std::is_same_v<onkigenerics::default_container_t<std::list<int>>, std::vector<int>>);
}