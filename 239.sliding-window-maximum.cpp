// @leet start
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> res;
        res.reserve(nums.size() - k + 1);
        for (int i = 0; i < k; ++i) {
            while (!window.empty() and window.back() < nums[i]) {
                window.pop_back();
            }
            window.push_back(nums[i]);
        }
        res.push_back(window.front());

        for (int i = 1; i <= nums.size() - k; ++i) {
            if (window.front() == nums[i - 1]) {
                window.pop_front();
            }
            while (!window.empty() and window.back() < nums[i + k - 1]) {
                window.pop_back();
            }
            window.push_back(nums[i + k - 1]);
            res.push_back(window.front());
        }
        return res;
    }
};
// @leet end
