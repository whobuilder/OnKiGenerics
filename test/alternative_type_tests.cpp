#include <catch2/catch.hpp>
#include <OnKiGenerics/alternative_type.hpp>

TEST_CASE("No alternative is given", "[alternative_type]")
{

    REQUIRE(std::is_same_v<onkigenerics::AlternativeType<std::vector<int>>, std::vector<int>>);
}

TEST_CASE("Alternative is given", "[alternative_type]")
{

    REQUIRE(std::is_same_v<onkigenerics::AlternativeType<std::vector<int>, std::list<int>>, std::list<int>>);
}

TEST_CASE("Alternative void is ignored", "[alternative_type]")
{

    REQUIRE(std::is_same_v<onkigenerics::AlternativeType<std::vector<int>, void>, std::vector<int>>);
}