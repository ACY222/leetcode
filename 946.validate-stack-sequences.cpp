// @leet start
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;

        while (i < pushed.size()) {
            if (!st.empty() and st.top() == popped[j]) {
                st.pop();
                ++j;
            } else {
                st.push(pushed[i]);
                ++i;
            }
        }

        while (j < popped.size()) {
            if (st.top() != popped[j]) { return false; }

            st.pop();
            ++j;
        }

        return true;
    }
};
// @leet end
