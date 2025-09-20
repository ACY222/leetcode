// @leet start
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<string> res;
    vector<vector<char>> map {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'h', 'g', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    void backtrack(const string& digits, string& path, int start) {
        if (start == digits.size()) {
            res.push_back(path);
            return;
        }

        for (const auto ch : map[digits[start] - '2']) {
            path.push_back(ch);
            backtrack(digits, path, start + 1);
            path.pop_back();
        }
    }
public:
    // 九键映射
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        string path;
        backtrack(digits, path, 0);
        return res;
    }
};
// @leet end
