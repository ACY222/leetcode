// @leet start
#include <vector>
using namespace std;
class Solution {
public:
    // valid: i <= j and nums1[i] <= nums2[j]
    // return 0 if no valid pairs
    // truly valid: i < j and nums1[i] <= nums2[j]
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 1;

        while (i < n1 and j < n2) {
            if (nums1[i] > nums2[j]) { ++i; }
            ++j;
        }

        return j - i - 1;
    }
};
// @leet end
