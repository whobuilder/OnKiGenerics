#include <catch2/catch.hpp>
#include <OnKiGenerics/remove_cvref.hpp>
#include <type_traits>
TEST_CASE("remove_cv_ref test", "[remove_cv_ref]")
{
    REQUIRE(std::is_same_v<onkigenerics::remove_cvref_t<const int &>, int>);
    REQUIRE(std::is_same_v<onkigenerics::remove_cvref_t<const int>, int>);
    REQUIRE(std::is_same_v<onkigenerics::remove_cvref_t<int &>, int>);
    REQUIRE(std::is_same_v<onkigenerics::remove_cvref_t<int>, int>);
}