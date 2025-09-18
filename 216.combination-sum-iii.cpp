// @leet start
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int>& path, int start, int count, int total) {
        if (count == 0) {
            if (total == 0) {
                res.push_back(path);
            }
            else {
                return;
            }
        }

        for (int num = start; num <= 9; ++num) {
            if (num > total) {  // so total >= 0 is always true
                return;
            }
            path.push_back(num);
            backtrack(path, num + 1, count - 1, total - num);
            path.pop_back();
        }
    }

public:
    // only 1-9 are used, and at most once
    // k numbers sum to be n
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;   // current result
        backtrack(path, 1, k, n);
        return res;
    }
};
// @leet end
