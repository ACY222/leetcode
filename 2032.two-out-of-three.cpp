// @leet start
#include <array>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                              vector<int>& nums3) {
        array<unsigned char, 101> freqs;

        for (int num : nums1) {
            freqs[num] |= 1;
        } // 001
        for (int num : nums2) {
            freqs[num] |= 2;
        } // 010
        for (int num : nums3) {
            freqs[num] |= 4;
        } // 100

        vector<int> res;
        for (int num = 1; num <= 100; ++num) {
            int freq = freqs[num];
            if ((freq & (freq - 1)) != 0) { res.push_back(num); }
        }

        return res;
    }
};
// @leet end
