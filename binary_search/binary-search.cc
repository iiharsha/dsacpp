#include "../template.h"

class Solution {
public:
  /**
   * Problem Statemet:
   *Given an array of integers nums which is sorted in ascending order, and an
   *integer target, write a function to search target in nums. If target
   *exists, then return its index. Otherwise, return -1.
   *
   *You must write an algorithm with O(log n) runtime complexity.
   */
  int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    for (int i = 0; i < nums.size(); ++i) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

int main(void) {
  fast;

  Solution sol;

  vector<int> nums = {2, 5};
  int target = 5;
  int res = sol.search(nums, target);

  cout << res << endl;
}
