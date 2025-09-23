// @leet start
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
    int dp(const string& w1, const string& w2, int i, int j) {
        // if i == -1 and j == -1, return 0, bingo
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;

        // if they are same
        if (w1[i] == w2[j]) {
            return dp(w1, w2, i - 1, j - 1);// skip
        }
        // if they are different
        else {
            return min({
                dp(w1, w2, i - 1, j - 1) + 1,   // replace
                dp(w1, w2, i, j - 1) + 1,       // insert
                dp(w1, w2, i - 1, j) + 1        // delete
            });
        }
}

public:
    int minDistance(string word1, string word2) {
        return dp(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};
// @leet end
