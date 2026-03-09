#include "../template.h"

class Solution
{
public:
  /**
   * Given an integer array nums, return an array answer such that answer[i] is
   * equal to the product of all the elements of nums except nums[i].
   *
   * The product of any prefix or suffix of nums is guaranteed to fit in a 32bit
   * integer.
   *
   * you must write an algorithm that runs in O(n) time without using the
   * division operation.
   */
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> answer(n);
    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = 1;
    suffix[n - 1] = 1;

    for (int i = 1; i < n; ++i)
    {
      prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; --i)
    {
      suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; ++i)
    {
      answer[i] = prefix[i] * suffix[i];
    }

    return answer;
  }
};

int main(void)
{
  fast;
  Solution sol;

  vector<int> nums = {1, 2, 3, 4};
  auto res = sol.productExceptSelf(nums);
  debug::printVector(res);
  return 0;
}
