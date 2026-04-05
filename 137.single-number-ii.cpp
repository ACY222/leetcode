// @leet start
#include <vector>
using std::vector;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum_by_digit{0};
        for (int i = 0; i < 32; ++i) {
            int sum_by_digit_i{0};
            for (auto num : nums) {
                sum_by_digit_i += (num >> i) & 1;
            }
            sum_by_digit_i %= 3;

            if (sum_by_digit_i != 0) { sum_by_digit |= (1 << i); }
        }
        return sum_by_digit;
    }
};
// @leet end
