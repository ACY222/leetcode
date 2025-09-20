// @leet start
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> res;

    string vector_to_string(const vector<int>& path) {
        string str {};
        for (int i = 0; i < 4; ++i) {
            if (i != 0) {
                str.append(".");
            }
            str += to_string(path[i]);
        }
        return str;
    }

    inline bool is_valid(int num) {
        return (num <= 255 and num >= 0);
    }

    void backtrack(const string& s, vector<int>& path, int start) {
        // if we have gone through the string and path is full
        if (start == s.size() and path.size() == 4) {
            res.push_back(vector_to_string(path));
            return;
        }
        // otherwise, if one of them is satisfied, we failed
        if (start == s.size() or path.size() == 4) {
            return;
        }

        // a number's length is in [1, 3]
        for (int i = 1; i < 4 and start + i <= s.size(); ++i) {
            int num = stoi(s.substr(start, i));
            // avoid the cases like 023
            if (s[start] == '0' and i != 1) {
                break;
            }
            if (!is_valid(num)) {
                continue;
            }
            path.push_back(num);
            backtrack(s, path, start + i);
            path.pop_back();
        }
    }
public:
    // each integer is in [0, 255]
    vector<string> restoreIpAddresses(string s) {
        vector<int> path;
        backtrack(s, path, 0);
        return res;
    }
};
// @leet end
