// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    auto findCommonPrefix(string& prefix, const string& str) {
        if (prefix.size() > str.size()) { prefix.erase(str.size()); }

        for (auto i {0}; i < str.size(); ++i) {
            if (prefix[i] != str[i]) {
                prefix.erase(i);
                return;
            }
        }
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        auto common_prefix {strs[0]};
        for (auto i {1}; i < strs.size() and common_prefix.size() > 0; ++i) {
            findCommonPrefix(common_prefix, strs[i]);
        }

        return common_prefix;
    }
};
// @leet end
