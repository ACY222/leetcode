// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int word_size;

    bool compare_two_words(const string& query, const string& word) {
        int count_diff = 0;
        for (int i = 0; i < word_size; ++i) {
            if (query[i] == word[i]) { continue; }

            ++count_diff;
            if (count_diff > 2) { return false; }
        }

        return true;
    }

public:
    // word.length() in [1, 100]
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        word_size = queries[0].size();
        vector<string> res;
        res.reserve(queries.size());
        for (auto& query : queries) {
            for (auto& word : dictionary) {
                if (!compare_two_words(query, word)) { continue; }

                res.push_back(query);
                break;
            }
        }

        return res;
    }
};
// @leet end
