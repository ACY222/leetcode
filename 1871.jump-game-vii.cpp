// @leet start
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    // i -> j: i + minJump <= j <= min(i + maxJump, s.size - 1) and s[j] == '0'
    // if I can reach j, I must come from i, where j - maxJump <= i <= j -
    // minJump
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (s.back() == '1') { return false; }

        stack<int> forward {{0}};
        stack<int> backward {{n - 1}};

        vector<bool> left_visited(n, false), right_visited(n, false);

        left_visited[0] = true, right_visited[n - 1] = true;

        while (!forward.empty() and !backward.empty()) {
            int left = forward.top();
            forward.pop();

            int right = backward.top();
            backward.pop();

            if (left_visited[right] == true or right_visited[left] == true) {
                return true;
            }

            for (int j = left + minJump; j <= min(left + maxJump, n - 1); ++j) {
                if (left_visited[j] == false and s[j] == '0') {
                    if (right_visited[j] == true) { return true; }

                    forward.push(j);
                    left_visited[j] = true;
                }
            }

            for (int i = right - minJump; i >= max(right - maxJump, 0); --i) {
                if (right_visited[i] == false and s[i] == '0') {
                    if (left_visited[i] == true) { return true; }

                    backward.push(i);
                    right_visited[i] = true;
                }
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
//
// 5 (2, 3)
