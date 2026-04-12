// @leet start
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // the first missing positive must in {1, 2, ..., size}
        int size = nums.size();
        vector<bool> is_missed(size, true);

        for (auto num : nums) {
            if (num <= 0 or num > size) { continue; }
            is_missed[num - 1] = false;
        }

        for (int i = 0; i < size; ++i) {
            if (is_missed[i]) { return i + 1; }
        }

        return size + 1;
    }
};
// @leet end
