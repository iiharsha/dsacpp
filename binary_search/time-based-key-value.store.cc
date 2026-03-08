#include "../template.h"

/**
 * PROBLEM STATEMENT :
 * Design a time-based key-value data structure that can store multiple values
 * for the same key at different time stamps and retrieve the key's value at a
 * certain timestamp.
 *
 * Implement the TimeMap class:
 *
 * TimeMap() Initializes the object of the data structure.
 *
 * void set(String key, String value, int timestamp) Stores the key with the
 * value at the given time timestamp.
 *
 * String get(String key, int timestamp) Returns a value such that set was
 * called previously, with timestamp_prev <= timestamp. If there are multiple
 * such values, it returns the value associated with the largest timestamp_prev.
 * If there are no values, it returns "".
 */

class TimeMap
{
public:
  unordered_map<string, vector<pair<string, int>>> map;
  TimeMap()
  {
  }

  /**
   * set stores the key with the value at the given timestamp.
   * All the timestamps of set are strictly increasing.
   */
  void set(string key, string value, int timestamp)
  {
    pair<string, int> val = {value, timestamp};
    map[key].push_back(val);
  }

  /**
   * Returns the value for a key at a given timestamp.
   * If the exact timestamp doesn't exist, return the closest earlier value.
   * If the key does not exist then return empty string.
   */
  string get(const string &key, int timestamp)
  {
    auto it = map.find(key);
    if (it == map.end())
    {
      return "";
    }

    auto &temp = it->second;
    int n = temp.size();
    int low = 0, high = n - 1;

    string ans = "";
    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (temp[mid].second <= timestamp)
      {
        ans = temp[mid].first;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return ans;
  }
};

int main(void)
{
  fast;
  TimeMap obj;
  obj.set("foo", "bar", 1);
  cout << obj.get("foo", 1) << '\n';

  cout << obj.get("foo", 3) << '\n';

  obj.set("foo", "bar2", 4);

  cout << obj.get("foo", 4) << '\n';
  cout << obj.get("foo", 5) << '\n';

  cout << obj.get("foo", 0) << '\n';

  obj.set("baz", "test", 2);
  cout << obj.get("baz", 2) << '\n';
  cout << obj.get("baz", 3) << '\n';
}
