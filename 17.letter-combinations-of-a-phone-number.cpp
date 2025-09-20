// @leet start
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<string> res;
    vector<string> map {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxzy"};

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
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        backtrack(digits, 0);
        return res;
    }
};
// @leet end
