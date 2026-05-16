// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    // 10 1 10 10 10
    //  l    m     r
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};
// @leet end
