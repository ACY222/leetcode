// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    bool inline is_vowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }

public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int num = 0;
        for (int idx = left; idx <= right; ++idx) {
            const string& word = words[idx];

            if (is_vowel(word.front()) and is_vowel(word.back())) { ++num; }
        }

        return num;
    }
};
// @leet end
