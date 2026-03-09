#include "../template.h"

class Solution
{
public:
  /**
   * Problem Statement :
   * Given an unsorted array of integers nums, return the length of the longest
   * consective elements sequence.
   *
   * You must write an algorithm that runs in O(n) time.
   */
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();

    int ans = 0;

    unordered_set<int> set;
    for (int num : nums)
    {
      set.insert(num);
    }

    for (int num : set)
    {
      if (set.find(num - 1) == set.end())
      {
        int length = 1;

        while (set.find(num + length) != set.end())
        {
          length++;
        }

        ans = max(length, ans);
      }
    }

    return ans;
  }
};

int main(void)
{
  fast;
  Solution sol;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  int res = sol.longestConsecutive(nums);
  cout << res << endl;
  return 0;
}
