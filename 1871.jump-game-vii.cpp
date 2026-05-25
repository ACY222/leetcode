// @leet start
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    // i -> j: i + minJump <= j <= min(i + maxJump, s.size - 1) and s[j] == '0'
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (s.back() == '1') { return false; }

        stack<int> st {{0}};
        while (!st.empty()) {
            int i = st.top();
            if (i == n - 1) { return true; }
            st.pop();

            for (int j = i + minJump; j <= min(i + maxJump, n - 1); ++j) {
                if (s[j] == '0') { st.push(j); }
            }
        }

        return false;
    }
};
// @leet end
//
// 0 1 2 3 4 5
// 0 1 1 0 1 0
//
// 0 (2, 3)
// 3 (5, 6)
// 5
