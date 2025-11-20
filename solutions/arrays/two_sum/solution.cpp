/*
 * https://leetcode.com/problems/two-sum/
 */

#include "solution.hpp"
#include <unordered_map>
#include <vector>

std::vector<int> TwoSum::twoSum(const std::vector<int> &nums, int target) {
  std::unordered_map<int, int> map;

  for (size_t i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];

    if (map.find(complement) != map.end()) {
      return {map[complement], static_cast<int>(i)};
    }

    map[nums[i]] = static_cast<int>(i);
  }
  return {};
}
