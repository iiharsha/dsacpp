#include "../template.h"

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    auto res = unique(nums.begin(), nums.end()) != nums.end();
    return res;
  }
};

int main(void) {
  fast;

  vector<int> v{1, 2, 3, 1};

  Solution sol;
  auto res = sol.containsDuplicate(v);
  if (res) {
    cout << "true\n";
  } else {
    cout << "true\n";
  }

  return 0;
}
