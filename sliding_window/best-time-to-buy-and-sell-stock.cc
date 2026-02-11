#include "../template.h"

class Solution {
public:
  int maxProfit(const vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }

    int maxProfit = 0;
    int hold = numeric_limits<int>::min();
    int release = numeric_limits<int>::min();

    for (const auto &p : prices) {
      hold = max(hold, -p);
      release = max(release, hold + p);
    }

    maxProfit = release;
    return maxProfit;
  }
};

int main(void) {
  fast;

  Solution sol;
  const vector<int> prices = {7, 1, 5, 3, 6, 4};
  int res = sol.maxProfit(prices);
  cout << res << endl;

  return 0;
}
