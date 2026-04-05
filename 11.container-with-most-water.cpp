// @leet start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto max_area{0};
        int i{0}, j{static_cast<int>(height.size() - 1)};

        while (i < j) {
            int height_i = height[i];
            int height_j = height[j];

            if (height_i <= height_j) {
                max_area = max(max_area, height_i * (j - i));
                while (i < j and height_i >= height[++i]) {}
            } else {
                max_area = max(max_area, height_j * (j - i));
                while (i < j and height_j >= height[--j]) {}
            }
        }

        return max_area;
    }
};
// @leet end
