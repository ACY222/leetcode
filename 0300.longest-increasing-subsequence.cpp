// @leet start
#include <vector>
using namespace std;
class Solution {
private:
    vector<int> poker_piles;

    void binary_search(int poker) {
        // [left, right], where right side is included
        int left = 0, right = poker_piles.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (poker_piles[mid] < poker) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (left == poker_piles.size()) {
            poker_piles.push_back(poker);
        }
        else {
            poker_piles[left] = poker;
        }
    }

public:
    // O(nlog(n)) time complexity
    int lengthOfLIS(vector<int>& nums) {
        int num_piles = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int poker = nums[i];
            binary_search(poker);
        }
        return poker_piles.size();
    }
};
// @leet end
