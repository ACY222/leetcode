// @leet start
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<string> res;
    vector<vector<char>> map {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'h', 'g', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    void backtrack(string& digits, int start) {
        if (start == digits.size()) {
            res.push_back(digits);
            return;
        }

        char digit = digits[start];
        for (const auto ch : map[digit - '2']) {
            digits[start] = ch;
            backtrack(digits, start + 1);
        }
        digits[start] = digit;
    }
public:
    // 九键映射
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        backtrack(digits, 0);
        return res;
    }
};
// @leet end
