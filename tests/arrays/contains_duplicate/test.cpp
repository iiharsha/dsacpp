#include <catch2/catch_test_macros.hpp>

#include "../../../solutions/arrays/contains_duplicate/solution.hpp"
#include <vector>

TEST_CASE("Contains Duplicate") {
  ContainsDuplicate solution;

  SECTION("Array with duplicates") {
    std::vector<int> nums = {1, 2, 3, 1};
    REQUIRE(solution.containsDuplicate(nums) == true);
  }

  SECTION("Array without duplicates") {
    std::vector<int> nums = {1, 2, 3, 4};
    REQUIRE(solution.containsDuplicate(nums) == false);
  }

  SECTION("Single element array") {
    std::vector<int> nums = {1};
    REQUIRE(solution.containsDuplicate(nums) == false);
  }

  SECTION("Empty array") {
    std::vector<int> nums = {};
    REQUIRE(solution.containsDuplicate(nums) == false);
  }

  SECTION("Large numbers with duplicate") {
    std::vector<int> nums = {100000, 200000, 300000, 100000};
    REQUIRE(solution.containsDuplicate(nums) == true);
  }
}
