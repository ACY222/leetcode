// @leet start
#include <algorithm>
#include <array>
#include <cstdint>
#include <string>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<int8_t, 26> counts;

        // 'A': 65
        // 'a': 97
        for_each(word.begin(), word.end(), [&counts](char c) {
            if (c >= 'a') {
                counts[c - 'a'] |= 2;
            } else {
                counts[c - 'A'] |= 1;
            }
        });

        int number = 0;
        for_each(counts.begin(), counts.end(), [&number](int8_t count) {
            if (count == 3) { ++number; }
        });
        return number;
    }
};
// @leet end
