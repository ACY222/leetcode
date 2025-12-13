// @leet start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = nums.empty() ? 0 : 1;
        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                int currLength = 1, currNum = num;
                while (numSet.count(currNum + 1)) {
                    ++currNum;
                    ++currLength;
                }
                maxLength = max(maxLength, currLength);
            }
        }
        return maxLength;
    }
};
// @leet end
