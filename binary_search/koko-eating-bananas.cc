#include "../template.h"

class Solution
{
public:
  /**
   * PROBLEM STATEMENT :
   * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
   * The guards have gone and will come back in h hours.
   * Koko can decide her bananas-per-hour eating speed of k. Each hour,
   * she chooses some pile of bananas and eats k bananas from that pile.
   * If the pile has less than k bananas, she eats all of them instead and will not eat any more
   * bananas during this hour.

   * Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

   * Return the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
   */
  int minEatingSpeed(vector<int> &piles, int h)
  {
    // [ 3, 6, 7, 11 ] h = 1
    // [ 0, 0, 0, 0]
    // hours = 8
    int n = piles.size();
    int maxPile = *max_element(piles.begin(), piles.end());

    int low = 1, high = maxPile;
    int ans = maxPile;
    while (low <= high)
    {
      int midPile = low + (high - low) / 2;
      long long totalHours = calculateTotalHours(piles, midPile);

      if (totalHours <= h)
      {
        ans = midPile;
        high = midPile - 1;
      }
      else
      {
        low = midPile + 1;
      }
    }
    return ans;
  }

private:
  long long calculateTotalHours(vector<int> &piles, int hourly)
  {
    long long totalHours = 0;
    for (int pile : piles)
    {
      totalHours += (pile + hourly - 1) / hourly;
    }
    return totalHours;
  }
};

int main(void)
{
  fast;
  Solution sol;

  vector<int> piles = {805306368, 805306368, 805306368};
  int h = 1000000000;
  int res = sol.minEatingSpeed(piles, h);
  cout << res << endl;
  return 0;
}