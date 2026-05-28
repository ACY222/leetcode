// @leet start
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    class Trie {
    private:
        struct TrieNode {
            array<unique_ptr<TrieNode>, 26> children {};
            int best_idx;

            TrieNode(int x) : best_idx(x) {}
        };

        unique_ptr<TrieNode> root;

        int search(const string& query) {
            auto curr = root.get();
            for (int i = query.size() - 1; i >= 0; --i) {
                int idx = query[i] - 'a';

                if (!curr->children[idx]) { return curr->best_idx; }

                curr = curr->children[idx].get();
            }

            return curr->best_idx;
        }

    public:
        Trie() : root(make_unique<TrieNode>(0)) {}

        void build(const vector<string>& words) {
            for (int index = 0; index < words.size(); ++index) {
                const auto& word = words[index];

                auto curr = root.get();
                if (word.size() < words[curr->best_idx].size()) {
                    curr->best_idx = index;
                }
                for (int i = word.size() - 1; i >= 0; --i) {
                    int idx = word[i] - 'a';

                    if (!curr->children[idx]) {
                        curr->children[idx] = make_unique<TrieNode>(index);
                    } else {
                        // if word.size is smaller, update index
                        if (word.size()
                            < words[curr->children[idx]->best_idx].size()) {
                            curr->children[idx]->best_idx = index;
                        }
                    }

                    curr = curr->children[idx].get();
                }
            }
        }

        vector<int> search_all(const vector<string>& queries) {
            vector<int> indices;
            indices.reserve(queries.size());

            for_each(queries.begin(), queries.end(),
                     [&indices, this](auto& query) {
                         indices.push_back(search(query));
                     });

            return indices;
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        Trie trie;
        trie.build(wordsContainer);
        return trie.search_all(wordsQuery);
    }
};
// @leet end
