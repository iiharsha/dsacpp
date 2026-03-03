#include "../template.h"

class Solution
{
public:
  bool searchInRoatedSortedArrayII(vector<int> &nums, int target)
  {
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target)
      {
        return true;
      }

      if (nums[low] == nums[mid] && nums[mid] == nums[high])
      {
        low++;
        high--;
        continue;
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
    return false;
  }
};

int main(void)
{
  fast;
  Solution sol;

  vector<int> nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
  int target = 3;

  bool res = sol.searchInRoatedSortedArrayII(nums, target);
  debug::printTrueOrNot(res);
  nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
  target = 10;
  res = sol.searchInRoatedSortedArrayII(nums, target);
  debug::printTrueOrNot(res);
}