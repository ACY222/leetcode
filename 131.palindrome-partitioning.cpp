// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<string>> res;

    bool is_palindrome(const string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left, --right;
        }
        return true;
    }

    void backtrack(const string& s, vector<string>& path,
                   int start) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        // end is included in current substr
        for (int end = start; end < s.size(); ++end) {
            if (is_palindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, path, end + 1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, path, 0);
        return res;
    }
};
// @leet end
