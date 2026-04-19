// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    // valid: i <= j and nums1[i] <= nums2[j]
    // return 0 if no valid pairs
    // truly valid: i < j and nums1[i] <= nums2[j]
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_dist = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        for (int i = 0; i < n1; ++i) {
            int j = i + max_dist + 1;
            while (j < n2 and nums1[i] <= nums2[j]) {
                ++max_dist;
                ++j;
            }
        }

        return max_dist;
    }
};
// @leet end
