#include "../template.h"

class Solution {
public:
  /*
   * Given two strings s and t, return the minimum window substring
   * of s such that every character in t (including duplicates)
   * exists in the window.
   *
   * Returns empty string if no such window exists.
   */
  string minWindow(string &s, string &t) {
    unordered_map<char, int> win_freq; // current window freq map
    int min_len = INT_MAX;
    int start_index = 0;

    unordered_map<char, int> t_freq; // target freq map
    for (char c : t) {
      t_freq[c]++;
    }

    int required = t_freq.size(); // unique chars required to match
    int left = 0, right = 0;

    int formed = 0; // to track how many unique characters match in the window

    while (right < s.size()) {
      char c = s[right];
      win_freq[c]++;

      if (t_freq.count(c) && win_freq[c] == t_freq[c]) {
        formed++;
      }

      while (left <= right && formed == required) {
        if ((right - left + 1) < min_len) {
          min_len = right - left + 1;
          start_index = left;
        }

        char leftChar = s[left];
        win_freq[leftChar]--;

        if (t_freq.count(leftChar) && win_freq[leftChar] < t_freq[leftChar]) {
          formed--;
        }

        left++;
      }

      right++;
    }

    return min_len == INT_MAX ? "" : s.substr(start_index, min_len);
  }
};

int main(void) {
  fast;

  Solution sol;

  string s = "ADOBECODEBANC";
  string t = "ABC";
  string res = sol.minWindow(s, t);

  cout << res << endl;

  return 0;
}
