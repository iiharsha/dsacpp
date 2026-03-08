#include "../template.h"

class Solution
{
public:
  /**
   *
   * Problem Statement:
   * Given an integer array nums, sorted in ascending order (with distinct
   * values) and a target value k. The array is rotated at some pivot point that
   * is unknown. Find the index at which k is present and if k is not present
   * return -1.
   */
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target)
      {
        return mid;
      }

      if (nums[low] <= nums[mid])
      {
        if (nums[low] <= target && target < nums[mid])
        {
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }
      }
      else
      {

        if (nums[mid] < target && target <= nums[high])
        {
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main(void)
{
  fast;
  Solution sol;

  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  int res = sol.search(nums, target);

  cout << res << "\n";
}