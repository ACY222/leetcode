// @leet start
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void backtrack(const vector<pair<int, int>>& group, vector<int>& path, int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < group.size(); ++i) {
            int val = group[i].first;
            int count = group[i].second;
            if (val > target) {
                break;
            }
            int max_count = min(count, target / val);
            for (int k = 1; k <= max_count; ++k) {
                for (int l = 0; l < k; ++l) {
                    path.push_back(val);
                }

                backtrack(group, path, i + 1, target - k * val);

                for (int l = 0; l < k; ++l) {
                    path.pop_back();
                }
            }
        }
    }
public:
    // this problem is quite similar to last one
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<pair<int, int>> group;   // num and its count
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i] > target) {   // the last numbers are too big
                break;
            }

            // if we find new number
            if (group.empty() or group.back().first != candidates[i]) {
                group.emplace_back(candidates[i], 1);
            }
            else {
                ++group.back().second;
            }
        }
        backtrack(group, path, 0, target);
        return res;
    }
};
// @leet end
