// @leet start
#include <algorithm>
#include <array>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    class Trie {
    private:
        struct TrieNode {
            // stores the index to child
            array<int, 26> children;
            int best_idx = -1;

            TrieNode() { children.fill(-1); }
        };

        vector<TrieNode> trie;

        void insert(const vector<string>& words, int index) {
            const string& word = words[index];
            int curr = 0;
            if (trie[curr].best_idx == -1
                or word.size() < words[trie[curr].best_idx].size()) {
                trie[curr].best_idx = index;
            }

            for (int idx = word.size() - 1; idx >= 0; --idx) {
                int char_idx = word[idx] - 'a';

                // if its child doesn't exist, create one
                if (trie[curr].children[char_idx] == -1) {
                    trie[curr].children[char_idx] = trie.size();
                    trie.emplace_back();
                }

                curr = trie[curr].children[char_idx];

                if (trie[curr].best_idx == -1
                    or word.size() < words[trie[curr].best_idx].size()) {
                    trie[curr].best_idx = index;
                }
            }
        }

        int search(const string& query) {
            int curr = 0;
            for (int idx = query.size() - 1; idx >= 0; --idx) {
                int char_idx = query[idx] - 'a';
                if (trie[curr].children[char_idx] == -1) { break; }

                curr = trie[curr].children[char_idx];
            }

            return trie[curr].best_idx;
        }

    public:
        Trie() { trie.emplace_back(); }

        void build(const vector<string>& words) {
            for (int index = 0; index < words.size(); ++index) {
                this->insert(words, index);
            }
        }

        vector<int> search_all(const vector<string>& queries) {
            vector<int> results;
            results.reserve(queries.size());

            for_each(queries.begin(), queries.end(),
                     [this, &results](const string& query) {
                         results.push_back(this->search(query));
                     });

            return results;
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
