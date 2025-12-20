// @leet start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);

            // if num >= all elements in tails
            if (it == tails.end()) {
                tails.push_back(num);
            }
            else {
                *it = num;
            }
        }
        return tails.size();
    }
};
// @leet end
