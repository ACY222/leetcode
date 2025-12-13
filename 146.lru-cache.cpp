// @leet start
#include <list>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int value;

    Node() : key(0), value(0) {}
    Node(int key, int value) : key(key), value(value) {}
};

class LRUCache {
private:
    list<Node> cacheList;
    unordered_map<int, list<Node>::iterator> keyToIter;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // if not exists
        if (keyToIter.find(key) == keyToIter.end()) {
            return -1;
        }
        // if exists, move it to the front
        cacheList.splice(cacheList.begin(), cacheList, keyToIter[key]);
        return cacheList.front().value;
    }

    void put(int key, int value) {
        // if exists, remove the old one, insert the new one and update map
        if (keyToIter.find(key) != keyToIter.end()) {
            keyToIter[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, keyToIter[key]);
            return;
        }
        // if not exists, remove the least recently used element
        // and insert the new one
        else {
            if (cacheList.size() == capacity) {
                auto [key_to_remove, value_to_remove] = cacheList.back();
                keyToIter.erase(key_to_remove);
                cacheList.pop_back();
            }
            cacheList.emplace_front(key, value);
            keyToIter[key] = cacheList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
