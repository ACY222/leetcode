#include <string>

using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (auto& child : children) {
                child = nullptr;
            }
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        auto curr = root;
        for (auto c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {  // if the path doesn't exist
                curr->children[index] = new TrieNode;
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        auto curr = root;
        for (auto c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        auto curr = root;
        for (auto c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */