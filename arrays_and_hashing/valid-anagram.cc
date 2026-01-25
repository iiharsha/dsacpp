#include "../template.h"

class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> check(26, 0);
    for (char c : s) {
      check[c - 'a']++;
    }
    for (char c : t) {
      check[c - 'a']--;
    }

    for (int i : check) {
      if (i != 0) {
        return false;
      }
    }

    return true;
  }
};

int main(void) {
  fast;

  string s = "anagram";
  string t = "nagaram";

  Solution sol;
  auto res = sol.isAnagram(s, t);
  if (res) {
    cout << "true\n";
  } else {
    cout << "true\n";
  }

  return 0;
}
