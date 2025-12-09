// @leet start
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
using std::vector;
using std::stack;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        stack<int> index;
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            while (!index.empty() and temperatures[index.top()] <= temperatures[i]) {
                index.pop();
            }
            res[i] = index.empty() ? 0 : index.top() - i;
            index.push(i);
        }
        return res;
    }
};
// @leet end
