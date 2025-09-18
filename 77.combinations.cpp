// @leet start
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int>& path, int start, int n, int count) {
        if (count == 0) {
            res.push_back(path);
        }

        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            backtrack(path, i + 1, n, count - 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        backtrack(path, 1, n, k);
        return res;
    }
};
// @leet end
