// @leet start
// #include <format>
// #include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int get_len_common_suffix(const string& word1, const string& word2) {
        int len = 0, i = word1.size() - 1, j = word2.size() - 1;
        while (i >= 0 and j >= 0 and word1[i] == word2[j]) {
            ++len;
            --i;
            --j;
        }

        return len;
    }

public:
    // longest common suffix
    // 1. smaller, 2. earlier
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int n = wordsQuery.size();
        vector<int> indices;
        indices.reserve(n);

        for (const string& query : wordsQuery) {
            int best_idx = 0;
            int max_len = get_len_common_suffix(query, wordsContainer[0]);

            for (int idx = 1; idx < wordsContainer.size(); ++idx) {
                const auto& word = wordsContainer[idx];

                int curr_len = get_len_common_suffix(query, word);

                if (curr_len > max_len
                    or (curr_len == max_len
                        and word.size() < wordsContainer[best_idx].size())) {
                    // cout << format("max_len = {}, max_idx = {}, curr_len
                    // =
                    // {}, "
                    //                "curr_idx = {}\n",
                    //                max_len_common, best_idx,
                    //                curr_len_common, idx);
                    best_idx = idx;
                    max_len = curr_len;
                }
            }

            indices.push_back(best_idx);
        }

        return indices;
    }
};
// @leet end
// int main() {
//     Solution sol;
//     vector<string> wordsContainer {"abcdefgh", "poiuygh", "ghghgh"},
//         wordsQuery {"gh", "acbfgh", "acbfegh"};
//
//     sol.stringIndices(wordsContainer, wordsQuery);
// }
