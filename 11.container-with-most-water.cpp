// @leet start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto max_area{0};
        auto i{0};
        auto j{height.size() - 1};

        while (i < j) {
            if (height[i] <= height[j]) {
                max_area = max<int>(max_area, height[i] * (j - i));
                ++i;
            } else {
                max_area = max<int>(max_area, height[j] * (j - i));
                --j;
            }
        }

        return max_area;
    }
};
// @leet end
