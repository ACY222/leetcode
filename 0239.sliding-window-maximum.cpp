// @leet start
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;      // store the indices instead of actual value
        vector<int> res;
        res.reserve(nums.size() - k + 1);

        for (int i = 0; i < nums.size(); ++i) {
            // pop back if the value at the tail is smaller than current value
            while (!dq.empty() and nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // pop front if the value at the head is out of the range
            if (dq.front() == i - k) {
                dq.pop_front();
            }

            // record the result if the window is constructed
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @leet end
