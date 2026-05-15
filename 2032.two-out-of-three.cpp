// @leet start
#include <array>
#include <vector>
using namespace std;
class Solution {
private:
    void process_nums(const vector<int>& nums, array<int, 101>& freqs,
                      int flag) {
        for (int num : nums) {
            freqs[num] |= (1 << flag);
        }
    }

public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                              vector<int>& nums3) {
        array<int, 101> freqs;
        // 10, 100, 1000
        //  2,   4,    8
        process_nums(nums1, freqs, 1);
        process_nums(nums2, freqs, 2);
        process_nums(nums3, freqs, 3);

        vector<int> res;
        for (int num = 1; num <= 100; ++num) {
            int freq = freqs[num];
            if ((freq & (freq - 1)) != 0) { res.push_back(num); }
        }

        return res;
    }
};
// @leet end
