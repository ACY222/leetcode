// @leet start
#include <unordered_map>
using std::unordered_map;

class Node {
public:
  int key, value;
  Node *next, *prev;
  Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
private:
  Node* head;
  Node* tail;
  int size;
public:
  DoubleLinkedList() {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  void addLast(Node* node) {
    node->prev = tail->prev;
    node->next = tail;
    tail->prev->next = node;
    tail->prev = node;
    ++size;
  }

  void remove(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    --size;
  }

  // for we need to update the map, where the key of the node is needed
  Node* removeFirst() {
    if (head->next == tail) {
      return {};  // the list is empty, nothing to remove
    }
    Node *firstNode = head->next;
    head->next = firstNode->next;
    firstNode->next->prev = head;
    --size;
    return firstNode;
  }

  int getSize() {
    return size;
  }
};

class LRUCache {
private:
  // this map maps from the key to the node, no matter where the node is
  unordered_map<int, Node*> keyToNode;
  DoubleLinkedList cache;
  int capacity;

  // make the existing node recently
  void makeRecently(Node* node) {
    cache.remove(node);
    cache.addLast(node);
    return;
  }

  // add a new node
  void addRecently(int key, int value) {
    Node *node = new Node(key, value);
    cache.addLast(node);
    keyToNode[key] = node;
    return;
  }

  // remove the first node, and erase the key in the map
  void removeLeatRecently() {
    Node *node = cache.removeFirst();
    keyToNode.erase(node->key);
    return;
  }

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
  }

  // return the value if the key exists, otherwise, return -1
  int get(int key) {
    if (!keyToNode.count(key)) {
      return -1;
    }
    makeRecently(keyToNode[key]);
    return keyToNode[key]->value;
  }

  // update the value of the key if the key exists, otherwise, add the key-value
  // to the cache. If the cache is full, evict the least recently used key
  void put(int key, int value) {
    // if the key exists, update the value and move it to the end
    if (keyToNode.count(key)) {
      Node* node = keyToNode[key];
      node->value = value;
      makeRecently(node);
      return;
    }
    // otherwise, add the node to the cache
    // if the cache is full, remove the least recently used one
    if (cache.getSize() == capacity) {
      removeLeatRecently();
    }
    addRecently(key, value);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
