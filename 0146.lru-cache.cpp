// @leet start
#include <unordered_map>
#include <utility>
#include <list>

using std::unordered_map;
using std::list;
using std::pair;

class LRUCache {
private:
    // it maps the key to the node's iterator in cache_list
    unordered_map<int, list<pair<int, int>>::iterator> key_to_iter;
    list<pair<int, int>> cache_list;    // key, value
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    // return the value and make it most recent if the key exists
    // otherwise, return -1
    int get(int key) {
        if (key_to_iter.find(key) == key_to_iter.end()) {
            return -1;
        }
        cache_list.splice(cache_list.begin(), cache_list, key_to_iter[key]);
        return key_to_iter[key]->second;
    }

    // update the value of the key if the key exists, otherwise, add the
    // key-value to the cache_list. If the cache is full, evict the least recently
    // used key
    void put(int key, int value) {
        // if the key exists, update the value and move it to the end
        if (key_to_iter.find(key) != key_to_iter.end()) {
            key_to_iter[key]->second = value;
            cache_list.splice(cache_list.begin(), cache_list, key_to_iter[key]);
            return;
        }
        // otherwise, add the node to the cache
        // if the cache is full, remove the least recently used one
        if (cache_list.size() == capacity) {
            int key_to_delete = cache_list.back().first;
            cache_list.pop_back();
            key_to_iter.erase(key_to_delete);
        }
        // add the new one
        cache_list.emplace_front(key, value);
        key_to_iter[key] = cache_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
