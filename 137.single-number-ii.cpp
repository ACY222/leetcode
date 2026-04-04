// @leet start
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        constexpr int INT_SIZE = 32;
        int sum_by_digit = 0;
        array<int, INT_SIZE> sum_each_digit{0};

        for (int i = 0; i < INT_SIZE; ++i) {
            for (auto num : nums) {
                sum_each_digit[i] += (num & (1 << i)) >> i;
            }
            sum_each_digit[i] %= 3;

            if (sum_each_digit[i] != 0) { sum_by_digit += 1 << i; }
        }

        return sum_by_digit;
    }
};
// @leet end
