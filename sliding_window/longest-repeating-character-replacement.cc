#include "../template.h"

/**
 * - create hashmap for char counts ch->count
 *   sliding window solution
 */
class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.length();
    int maxCount = 0, left = 0, result = 0;

    unordered_map<char, int> charCount;

    for (int right = 0; right < n; ++right) {
      char rChar = s[right];
      char lChar = s[left];
      charCount[rChar]++;
      maxCount = max(maxCount, charCount[rChar]);

      while ((right - left + 1) - maxCount > k) {
        charCount[lChar]--;
        left++;
      }

      result = max(result, right - left + 1);
    }
    return result;
  }
};

int main(void) {
  fast;

  Solution sol;
  int k = 2;
  string s = "ABAB";
  auto res = sol.characterReplacement(s, k);
  cout << res << endl;

  k = 1;
  s = "AABABBA";
  res = sol.characterReplacement(s, k);
  cout << res << endl;

  return 0;
}
