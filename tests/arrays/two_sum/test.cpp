#include <catch2/catch_test_macros.hpp>

#include "../../../solutions/arrays/two_sum/solution.hpp"
#include <vector>

TEST_CASE("Two Sum") {
  TwoSum solution;

  SECTION("Example 1") {
    REQUIRE(solution.twoSum({2, 7, 11, 15}, 9) == std::vector<int>({0, 1}));
  }

  SECTION("Example 2") {
    REQUIRE(solution.twoSum({3, 2, 4}, 6) == std::vector<int>({1, 2}));
  }

  SECTION("Example 3") {
    REQUIRE(solution.twoSum({3, 3}, 6) == std::vector<int>({0, 1}));
  }
}
