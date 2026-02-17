#include "../template.h"

class Solution {
private:
  void printPermutation(const vector<int> &nums) {
    cout << '[';
    for (int val : nums) {
      cout << val;
    }
    cout << "]\n";
  }

public:
  /*
   */
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int index = -1;

    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        index = i;
        break;
      }
    }

    if (index == -1) {
      reverse(nums.begin(), nums.end());
      printPermutation(nums);
      return;
    }

    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] > nums[index]) {
        swap(nums[i], nums[index]);
        break;
      }
    }

    reverse(nums.begin() + index + 1, nums.end());

    printPermutation(nums);
  }
};

int main(void) {
  fast;

  Solution sol;

  vector<int> nums = {3, 2, 1};
  sol.nextPermutation(nums);

  return 0;
}
