// @leet start
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;

    void backtrack(const vector<pair<int, int>>& valueAndCount,
                   vector<int>& path, int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < valueAndCount.size(); ++i) {
            int value = valueAndCount[i].first;
            int count = valueAndCount[i].second;
            if (value > target) {
                return;
            }
            int maxCount = min(count, target / value);

            for (int k = 1; k <= maxCount; ++k) {
                for (int l = 0; l < k; ++l) {
                    path.push_back(value);
                }
                backtrack(valueAndCount, path, i + 1, target - k * value);
                for (int l = 0; l < k; ++l) {
                    path.pop_back();
                }
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<pair<int, int>> valueAndCount;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) {
            // if the rest of the candidats are too big, just skip them
            if (candidates[i] > target) {
                break;
            }
            // if this is a new number
            if (valueAndCount.empty() or valueAndCount.back().first != candidates[i]) {
                valueAndCount.emplace_back(candidates[i], 1);
            }
            else {  // if we have seen this number before
                ++valueAndCount.back().second;
            }
        }
        backtrack(valueAndCount, path, 0, target);
        return res;
    }
};
// @leet end
