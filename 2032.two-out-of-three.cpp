// @leet start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
private:
    void process_nums(const vector<int>& nums, unordered_map<int, int>& freqs,
                      int flag) {
        for (int num : nums) {
            freqs[num] |= (1 << flag);
        }
    }

public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                              vector<int>& nums3) {
        unordered_map<int, int> freqs;
        // 10, 100, 1000
        //  2,   4,    8
        process_nums(nums1, freqs, 1);
        process_nums(nums2, freqs, 2);
        process_nums(nums3, freqs, 3);

        vector<int> res;
        for (auto [num, freq] : freqs) {
            if (freq == 6 or freq == 10 or freq == 12 or freq == 14) {
                res.push_back(num);
            }
        }

        return res;
    }
};
// @leet end
