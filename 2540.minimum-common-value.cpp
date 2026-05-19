// @leet start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        auto it1 = nums1.begin(), it2 = nums2.begin();

        while (it1 != nums1.end() and it2 != nums2.end()) {
            if (*it1 == *it2) { return *it1; }

            // try to find *it2 in nums1
            if (*it1 < *it2) {
                auto iter = lower_bound(it1, nums1.end(), *it2);
                if (iter != nums1.end() and *iter == *it2) {
                    return *it2;
                } else {
                    it1 = iter;
                }
            }
            // try to find *it1 in nums2
            else {
                auto iter = lower_bound(it2, nums2.end(), *it1);
                if (iter != nums2.end() and *iter == *it1) {
                    return *it1;
                } else {
                    it2 = iter;
                }
            }
        }

        return -1;
    }
};
// @leet end
