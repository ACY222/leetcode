// @leet start
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) { return "1"; }
        string prev = "1";
        string curr;

        for (int m = 2; m <= n; ++m) {
            int count {1}, idx {0};

            while (idx < prev.size()) {
                while (idx < prev.size() - 1 and prev[idx] == prev[idx + 1]) {
                    ++idx;
                    ++count;
                }

                curr.push_back(count + '0');
                curr.push_back(prev[idx]);

                count = 1;
                ++idx;
            }

            prev = curr;
            curr.clear();
        }
        return prev;
    }
};
// @leet end
