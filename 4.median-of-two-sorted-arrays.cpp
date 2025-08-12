// @leet start
#include <vector>
#include <algorithm>
#include <climits>
using std::vector;
using std::max, std::min;
using std::swap;
class Solution {
public:
  // // the time complexity is O((m+n)log(m+n)) because of sort
  // // so it's slow
  // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  //   nums1.insert(nums1.end(), nums2.begin(), nums2.end());
  //   sort(nums1.begin(), nums1.end());
  //   if (nums1.size() % 2 == 1) {    // if nums1's size is odd
  //     return double(nums1[nums1.size() / 2]);
  //   }
  //   else {
  //     return ((double)nums1[nums1.size() / 2] + (double)nums1[nums1.size() / 2 - 1]) / 2;
  //   }
  // }
  //
  //
  // // if I sort them by myself, the time complexity is O(m+n), which is faster
  // // and I can also terminate a bit earlier, so the time complexity is O((m+n)/2)
  // // but it's still very slow
  // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  //   vector<int> nums {};
  //   int size { (int)(nums1.size() + nums2.size()) }, i {0}, j {0}, count { size / 2 + 1};
  //   for (; i < nums1.size() && j < nums2.size() && count > 0; --count) {
  //     if (nums1[i] < nums2[j]) {
  //       nums.push_back(nums1[i++]);
  //     }
  //     else {
  //       nums.push_back(nums2[j++]);
  //     }
  //   }
  //   while (count > 0 && i < nums1.size()) {
  //     nums.push_back(nums1[i++]);
  //     --count;
  //   }
  //   while (count > 0 && j < nums2.size()) {
  //     nums.push_back(nums2[j++]);
  //     --count;
  //   }
  //   if (size % 2 == 1) {    // if nums's size is odd
  //     return (double)nums.back();
  //   }
  //   else {
  //     return ((double)nums.back() + (double)nums[nums.size() - 2]) / 2;
  //   }
  // }
  //
  //
  // this algorithm is super fast
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // swap if necessary to make nums1 smaller
    if (nums1.size() > nums2.size()) {
      swap(nums1, nums2);
    }
    int m {(int)nums1.size()}, n {(int)nums2.size()};
    int left {0}, right {m};    // the range to search: [left, right)
    int leftCount { (m + n + 1) / 2};   // so that if m+n is odd, the left has 1 more element
    while (left <= right) {
      // if left, right are very big, code in this way can prevent overflowing
      int i {left + (right - left) / 2}, j {leftCount - i};

      int nums1LeftMax { i == 0 ? INT_MIN : nums1[i - 1] },
          nums1RightMin { i == m ? INT_MAX : nums1[i] },
          nums2LeftMax { j == 0 ? INT_MIN : nums2[j - 1] },
          nums2RightMin { j == n ? INT_MAX : nums2[j] };
      int leftMax { max(nums1LeftMax, nums2LeftMax) },
          rightMin { min(nums1RightMin, nums2RightMin) };
      // if the vectors are divided properly
      if (leftMax <= rightMin) {
        // if the total size is odd
        if ((m + n) % 2 == 1) {
          return (double)leftMax;
        }
        else {
          return ((double)leftMax + (double)rightMin) / 2.0;
        }
      }
      // if the vectors haven't been divided properly, we need to move the
      // separators
      else if (nums1LeftMax > nums2RightMin) {
        // using i - 1, i + 1 so that the original separator can be ignored
        right = i - 1;
      }
      else {
        left = i + 1;
      }
    }
    return 0.0;
  }
};
// @leet end
