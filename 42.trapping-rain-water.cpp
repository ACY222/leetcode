// @leet start
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> max_neighbors(height.size());
        int max_left = 0, max_right = 0, res = 0;

        for (int i = 0; i < height.size(); ++i) {
            max_neighbors[i].first = max_left;
            max_left = max(max_left, height[i]);
        }

        for (int i = height.size() - 1; i >= 0; --i) {
            max_neighbors[i].second = max_right;
            max_right = max(max_right, height[i]);
        }

        for (int i = 0; i < height.size(); ++i) {
            res += max(min(max_neighbors[i].first, max_neighbors[i].second) - height[i], 0);
        }
        return res;
    }
};
// @leet end
