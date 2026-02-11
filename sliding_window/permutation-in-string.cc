#include "../template.h"

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
      return false;
    }

    vector<int> freq(26, 0);
    for (char c : s1) {
      freq[c - 'a']++;
    }

    int count = s1.size();
    int l = 0, r = 0;

    while (r < s2.size()) {
      if (freq[s2[r] - 'a'] > 0) {
        count--;
      }

      freq[s2[r] - 'a']--;
      r++;

      while (count == 0) {
        if (r - l == s1.size()) {
          return true;
        }

        if (freq[s2[l] - 'a'] == 0) {
          count++;
        }
        freq[s2[l] - 'a']++;
        l++;
      }
    }

    return false;
  }
};

void printAnswer(bool result) {
  if (result) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }
}

int main(void) {
  fast;

  Solution sol;

  string s1 = "ab", s2 = "eidbaoo";
  auto res = sol.checkInclusion(s1, s2);
  printAnswer(res);

  s1 = "ab";
  s2 = "eidboaoo";
  res = sol.checkInclusion(s1, s2);
  printAnswer(res);

  return 0;
}
