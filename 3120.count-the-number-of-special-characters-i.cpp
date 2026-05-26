// @leet start
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
        for (char c : word) {
            if (c >= 'a') { // a-z
                counts[c - 'a'] |= 2;
            } else { // A-Z
                counts[c - 'A'] |= 1;
            }
        }

        int number = 0;
        for (int count : counts) {
            if (count == 3) { ++number; }
        }
        return number;
    }
};
// @leet end
