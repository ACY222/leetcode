// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // i -> j: i + minJump <= j <= min(i + maxJump, s.size - 1) and s[j] == '0'
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (s[n - 1] == '1') { return false; }

        vector<bool> dp(n, false);
        dp[0] = true;

        int active = 0; // the count of reachable points in the window
        for (int i = 1; i < n; ++i) {
            if (i >= minJump and dp[i - minJump]) { ++active; }

            if (i > maxJump and dp[i - maxJump - 1]) { --active; }

            if (s[i] == '0' and active > 0) { dp[i] = true; }
        }

        return dp[n - 1];
    }
};
// @leet end
