// @leet start
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    // one operation: delete the rightmost character of a string
    int findMinimumOperations(string s1, string s2, string s3) {
        if (s1[0] != s2[0] or s2[0] != s3[0]) { return -1; }

        int min_size = min(min(s1.size(), s2.size()), s3.size()), idx = 1;
        while (idx < min_size) {
            if (s1[idx] != s2[idx] or s2[idx] != s3[idx]) { break; }
            ++idx;
        }

        return (s1.size() + s2.size() + s3.size()) - 3 * idx;
    }
};
// @leet end
