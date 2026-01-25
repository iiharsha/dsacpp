#include "../template.h"

class Solution {
  public:
    vector<int> twoSum(const vector<int> &nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];

            if (map.count(complement)) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }

        return {};
    }
};

int main(void) {
    fast;

    Solution sol;

    const vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto res = sol.twoSum(nums, target);

    if (!res.empty()) {
        cout << res[0] << res[1] << "\n";
    } else {
        cout << "No Solution \n";
    }

    return 0;
}
