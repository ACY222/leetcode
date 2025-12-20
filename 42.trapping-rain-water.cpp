// @leet start
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_neighbors(height.size());
        int max_left = 0, max_right = 0, res = 0;
        for (int i = 0; i < height.size(); ++i) {
            max_neighbors[i] = max_left;
            max_left = max(max_left, height[i]);
        }

        for (int i = height.size() - 1; i >= 0; --i) {
            max_neighbors[i] = min(max_neighbors[i], max_right);
            max_right = max(max_right, height[i]);
        }

        for (int i = 0; i < height.size(); ++i) {
            res += max(max_neighbors[i] - height[i], 0);
        }
        return res;
    }
};
// @leet end
