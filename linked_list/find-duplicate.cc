#include "../template.h"

/*
  Given an array of integers nums containing n + 1 integers where each integer
  is in the range ' [1, n] inclusive. There is only one repeated number in nums,
  return this repeated number. You must solve the problem without modifying the
  array nums and using only constant extra space.
*/

class Solution {
public:
  int findDuplicate(const vector<int> &nums) {
    int slowptr = nums[0];
    int fastptr = nums[nums[0]];

    while (slowptr != fastptr) {
      slowptr = nums[slowptr];
      fastptr = nums[nums[fastptr]];
    }

    fastptr = 0;
    while (slowptr != fastptr) {
      slowptr = nums[slowptr];
      fastptr = nums[fastptr];
    }
    return slowptr;
  }
};

int main(void) {
  fast;
  Solution sol;

  const vector<int> nums = {1, 3, 4, 2, 2};
  auto result = sol.findDuplicate(nums);

  cout << "result: " << result << "\n";

  return 0;
}
