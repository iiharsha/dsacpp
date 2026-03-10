#include "../template.h"
#include <algorithm>

class Solution
{
public:
  /**
   * Given two sorted arrays nums1 and nums2 of size m and n respectively,
   * return the median of the two sorted arrays.
   *
   * The overall runtime complexity should be O(log (m+n)).
   */
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;

    while (low <= high)
    {
      int cut1 = low + (high - low) / 2;
      int cut2 = (n1 + n2 + 1) / 2 - cut1;

      int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
      int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
      int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
      int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

      if (l1 <= r2 && l2 <= r1)
      {
        if ((n1 + n2) % 2 == 0)
        {
          return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else
        {
          return max(l1, l2);
        }
      }
      else if (l1 > l2)
      {
        high = cut1 - 1;
      }
      else
      {
        low = cut1 + 1;
      }
    }
    return 0.0;
  }
};

int main(void)
{
  fast;
  Solution sol;

  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  auto res = sol.findMedianSortedArrays(nums1, nums2);
  cout << res << endl;

  return 0;
}
