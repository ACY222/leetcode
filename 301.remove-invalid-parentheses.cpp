// @leet start
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_set<string> valid_string;

    void dfs(int index, int left_remain, int right_remain, int pair, string& path, const string& s) {
        // up to now, num(close parenthese) > num(open parenthese), it must be invalid
        if (pair < 0) return;

        // we have removed too many parentheses
        if (left_remain < 0 or right_remain < 0) return;

        // if we haved reached the end
        if (index == s.size()) {
            // if the string is valid
            if (left_remain == 0 and right_remain == 0 and pair == 0) {
                valid_string.insert(path);
            }
            // whether valid or not, backtrace
            return;
        }

        char c = s[index];
        if (c == '(') {
            // choice 1: reserve the parenthese
            path.push_back(c);
            dfs(index + 1, left_remain, right_remain, pair + 1, path, s);
            path.pop_back();

            // choice 2: remove the parenthese
            dfs(index + 1, left_remain - 1, right_remain, pair, path, s);
        }
        else if (c == ')') {
            // choice 1: reserve the parenthese
            path.push_back(c);
            dfs(index + 1, left_remain, right_remain, pair - 1, path, s);
            path.pop_back();
            // choice 2: remove the parenthese
            dfs(index + 1, left_remain, right_remain - 1, pair, path, s);
        }
        // if c is a letter
        else {
            path.push_back(c);
            dfs(index + 1, left_remain, right_remain, pair, path, s);
            path.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        valid_string.clear();
        int left_remain = 0, right_remain = 0;
        string path = "";
        for (char c : s) {
            if (c == '(') {
                ++left_remain;
            }
            else if (c == ')') {
                if (left_remain > 0) {
                    --left_remain;
                }
                else {
                    ++right_remain;
                }
            }
        }

        dfs(0, left_remain ,right_remain, 0, path, s);
        return vector<string>(valid_string.begin(), valid_string.end());
    }
};
// @leet end
