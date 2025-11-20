#include "solution.hpp"
#include <unordered_map>
#include <vector>

bool ContainsDuplicate::containsDuplicate(std::vector<int> &nums) {
  std::unordered_map<int, int> seen;

  for (int num : nums) {
    if (seen[num] >= 1) {
      return true;
    } else {

      seen[num]++;
    }
  }

  return false;
}
