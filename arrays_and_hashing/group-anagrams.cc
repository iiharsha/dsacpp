#include "../template.h"

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> groups;
    for (const auto &str : strs) {
      string temp{str};
      sort(temp.begin(), temp.end());
      groups[temp].emplace_back(str);
    }

    vector<vector<string>> anagrams;
    for (const auto &kvp : groups) {
      vector<string> group;
      for (const auto &str : kvp.second) {
        group.emplace_back(str);
      }
      // sort(group.begin(), group.end());
      anagrams.emplace_back(group);
    }

    return anagrams;
  }
};

int main(void) {
  fast;

  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution sol;
  auto res = sol.groupAnagrams(strs);

  cout << "[";
  for (const auto group : res) {
    cout << "[";
    for (const auto strs : group) {
      cout << strs;
    }
    cout << "]";
  }

  cout << "]";
  cout << "\n";

  return 0;
}
