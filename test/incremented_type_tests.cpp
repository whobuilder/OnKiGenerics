#include <catch2/catch.hpp>
#include <OnKiGenerics/incremented_type.hpp>
#include <vector>
#include <type_traits>
#include <list>
#include <deque>
#include <forward_list>
TEMPLATE_TEST_CASE("incremented type does not change for dynamic containers",
  "[incremented_t]",
  std::vector<int>,
  std::list<int>,
  std::deque<int>,
  std::forward_list<int>)
{
    REQUIRE(std::is_same_v<onkigenerics::incremented_t<TestType, 1>, TestType>);
}

TEST_CASE("check incremented type for arrays", "[incremented_t]")
{
    REQUIRE(std::is_same_v<onkigenerics::incremented_t<std::array<double, 3>, -2>, std::array<double, 1>>);
    REQUIRE(std::is_same_v<onkigenerics::incremented_t<int[6], 1>, int[7]>);
}