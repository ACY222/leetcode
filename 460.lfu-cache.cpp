// @leet start
#include <unordered_map>
#include <list>
using std::unordered_map;
using std::list;
class LFUCache {
private:
  unordered_map<int, int> keyToVal;
  unordered_map<int, int> keyToFreq;
  unordered_map<int, list<int>> freqToKeys;
  unordered_map<int, list<int>::iterator> keyToIters;
  int minFreq, cap;

  void increaseFreq(int key) {
    int freq = keyToFreq[key];
    ++keyToFreq[key];
    freqToKeys[freq].erase(keyToIters[key]);
    freqToKeys[freq + 1].push_back(key);
    keyToIters[key] = --freqToKeys[freq + 1].end();
    // if key is the only element in freqToKeys[minFreq], increase minFreq
    if (minFreq == freq and freqToKeys[freq].empty()) {
      ++minFreq;
    }
  }

  void removeMinFreqKey() {
    list<int>& minFreqKeys = freqToKeys[minFreq];
    // remove the first key in the set
    // for we will insert the recently used element in the end
    int keyToDelete = minFreqKeys.front();
    // remove it from all maps
    keyToVal.erase(keyToDelete);
    keyToFreq.erase(keyToDelete);
    minFreqKeys.pop_front();
    keyToIters.erase(keyToDelete);
    // make sure that the cache is not empty, otherwise there will be an
    // infinite loop
    if (keyToVal.empty()) {
      minFreq = 0;
      return;
    }
    while (freqToKeys[minFreq].empty()) {
      ++minFreq;
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
    if (!keyToVal.count(key)) {
      return -1;
    }
    increaseFreq(key);
    return keyToVal[key];
  }

  void put(int key, int value) {
    if (this->cap <= 0) {
      return;
    }
    // If it exists, increase the frequency and then return its value
    if (keyToVal.count(key)) {
      // update the value
      keyToVal[key] = value;
      increaseFreq(key);
      return;
    }
    // If it doesn't exist, check if it's full
    if (keyToVal.size() == cap) {
      removeMinFreqKey();
    }
    keyToVal[key] = value;
    keyToFreq[key] = 1;
    freqToKeys[1].push_back(key);
    keyToIters[key] = --freqToKeys[1].end();
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
