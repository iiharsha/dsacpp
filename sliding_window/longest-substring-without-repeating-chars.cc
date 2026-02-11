#include "../template.h"

/**
 * must have unique characters for a substring
 * invalid -> "abcabc"
 * valid -> "abc"
 */
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    unordered_map<char, int> lookup;
    for (int left = 0, right = 0; right < s.size(); ++right) {
      if (lookup.count(s[right])) {
        left = max(left, lookup[s[right]] + 1);
      }
      lookup[s[right]] = right;
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};

int main(void) {
  fast;

  Solution sol;
  string s = "abcabcbb";
  auto res = sol.lengthOfLongestSubstring(s);
  cout << res << endl;

  s = "pwwkew";
  res = sol.lengthOfLongestSubstring(s);
  cout << res << endl;

  s = "bbbbb";
  res = sol.lengthOfLongestSubstring(s);
  cout << res << endl;

  return 0;
}
