// @leet start
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct Node {
    int min;
    int max;

    Node() : min(0), max(0) {}
    Node(int min, int max) : min(min), max(max) {}
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        Node prev(nums[0], nums[0]), curr;
        int max_val = INT_MIN;
        max_val = max(max_val, prev.max);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                curr.max = max(nums[i], nums[i] * prev.max);
                curr.min = min(nums[i], nums[i] * prev.min);
            }
            else {
                curr.max = max(nums[i], nums[i] * prev.min);
                curr.min = min(nums[i], nums[i] * prev.max);
            }
            max_val = max(max_val, curr.max);
            prev = curr;
        }
        return max_val;
    }
};
// @leet end
