// @leet start
#include <unordered_map>
#include <utility>
#include <deque>
#include <list>
using std::unordered_map;
using std::pair;
using std::list;
class LFUCache {
private:
  unordered_map<int, pair<int, int>> keyToValAndFreq;
  unordered_map<int, list<int>> freqToKey;
  unordered_map<int, list<int>::iterator> keyToIterator;
  int cap;
  int minFreq;

  void increaseFreq(int key) {
    int freq = keyToValAndFreq[key].second;
    ++keyToValAndFreq[key].second;
    freqToKey[freq].erase(keyToIterator[key]);
    freqToKey[freq + 1].push_back(key);
    keyToIterator[key] = --freqToKey[freq + 1].end();
    // If key is the only element with minFreq, increase minFreq
    if (minFreq == freq and freqToKey[freq].empty()) {
      ++minFreq;
    }
  }

  void removeLeastFreqUsed() {
    if (cap <= 0 or keyToValAndFreq.empty()) {
      return;
    }
    int keyToDelete = freqToKey[minFreq].front();
    freqToKey[minFreq].pop_front();
    keyToValAndFreq.erase(keyToDelete);
    keyToIterator.erase(keyToDelete);
    if (keyToValAndFreq.empty()) {
      minFreq = 0;
    }
    else {
      // if it's not empty, we may increase the minFreq
      while (freqToKey[minFreq].empty()) {
        ++minFreq;
      }
    }
  }

public:
  LFUCache(int capacity) {
    cap = capacity;
    minFreq = 0;
  }

  // If the key exists, return the value, don't forget to increase the frequency
  // maybe we also need to update minFreq
  int get(int key) {
    if (!keyToValAndFreq.count(key)) {
      return -1;
    }
    increaseFreq(key);
    return keyToValAndFreq[key].first;
  }

  void put(int key, int value) {
    if (keyToValAndFreq.count(key)) {
      keyToValAndFreq[key].first = value;
      increaseFreq(key);
      return;
    }
    // if the cache is full, we need to remove the LFU element
    if (keyToValAndFreq.size() == cap) {
      removeLeastFreqUsed();
    }
    keyToValAndFreq[key] = {value, 1};
    freqToKey[1].push_back(key);
    keyToIterator[key] = --freqToKey[1].end();
    minFreq = 1;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
