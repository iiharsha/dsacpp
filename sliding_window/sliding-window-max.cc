#include "../template.h"

class Solution
{
public:
  /*
   *  PROBLEM STATEMENT :
   *  You are given an array of integers nums, there is a sliding window of
   *  size k which is moving from the very left of the array to the very right.
   *  You can only see the k numbers in the window. Each time the sliding window
   *  moves right by one position.

   *  Return the max sliding window.
   */
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    int n = nums.size();

    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < n; ++i)
    {
      // pop front if the they are out of the window's range
      if (!dq.empty() && dq.front() <= i - k)
      {
        dq.pop_front();
      }

      while (!dq.empty() && nums[dq.back()] < nums[i])
      {
        dq.pop_back();
      }

      dq.push_back(i);

      if (i >= k - 1)
      {
        result.push_back(nums[dq.front()]);
      }
    }

    return result;
  }
};

int main(void)
{
  fast;

  Solution sol;
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  auto res = sol.maxSlidingWindow(nums, k);

  for (int val : res)
  {
    cout << val << " " << endl;
  }

  return 0;
}