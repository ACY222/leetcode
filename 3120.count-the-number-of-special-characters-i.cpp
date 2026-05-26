// @leet start
#include <algorithm>
#include <bitset>
#include <string>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26> lower, upper;

        for_each(word.begin(), word.end(), [&lower, &upper](char c) {
            if (c >= 'a') {
                lower[c - 'a'] = true;
            } else {
                upper[c - 'A'] = true;
            }
        });

        return (lower & upper).count();
    }
};
// @leet end
