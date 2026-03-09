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

    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;

    int index2 = n / 2;
    int index1 = index2 - 1;

    int count = 0, i = 0, j = 0;
    int index1el = -1, index2el = -1;

    while (i < n1 && j < n2)
    {
      if (nums1[i] < nums2[j])
      {
        if (count == index1)
          index1el = nums1[i];

        if (count == index2)
          index2el = nums1[i];
        i++;
      }
      else
      {
        if (count == index1)
          index1el = nums2[j];

        if (count == index2)
          index2el = nums2[j];
        j++;
      }
      count++;
    }

    while (i < n1)
    {
      if (count == index1)
        index1el = nums1[i];
      if (count == index2)
        index2el = nums1[i];
      count++;
      i++;
    }

    while (j < n2)
    {
      if (count == index1)
        index1el = nums2[j];
      if (count == index2)
        index2el = nums2[j];
      count++;
      j++;
    }

    if (n % 2 == 1)
      return (double)index2el;

    return (double)(index1el + index2el) / 2.0;
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
