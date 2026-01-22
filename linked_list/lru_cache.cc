#include "../template.h"

/**
 * LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 *
 * Solution uses List and HashMap
 */
class LRUCache {

public:
  LRUCache(int capacity) : capacity_(capacity) {};

  /**
   * returns the value of key if the key exists, otherwise returns -1
   */
  int get(int key) {
    if (!map_.count(key)) {
      return -1;
    }

    const auto value = map_[key]->second;
    update(key, value);
    return value;
  }

  /**
   * update the value of the key if its exists.
   * Otherwise, add the key-value pair to the cache.
   * If the number of keys exceeds the capacity from this operation,
   * evict the least recently used key.
   */
  void put(int key, int value) {
    if (capacity_ <= 0) {
      return;
    }
    if (!map_.count(key) &&
        list_.size() == static_cast<unsigned long>(capacity_)) {
      auto del = list_.back();
      list_.pop_back();
      map_.erase(del.first);
    }
    update(key, value);
  }

private:
  int capacity_;
  list<pair<int, int>> list_; //[[key:value], [key:value]
  unordered_map<int, list<pair<int, int>>::iterator> map_;

  void update(int key, int value) {
    auto it = map_.find(key);
    if (it != map_.end()) {
      // erase the [key:value]
      list_.erase(it->second);
    }

    list_.emplace_front(key, value);
    map_[key] = list_.begin();
  }
};

int main() {
  fast;

  LRUCache lRUCache(2);
  lRUCache.put(2, 4);
  int ans = lRUCache.get(2);
  // cout << ans << endl;

  return 0;
}
