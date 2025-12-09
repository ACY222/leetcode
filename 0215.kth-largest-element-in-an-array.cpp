#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::swap;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
        // return nums[k - 1];
        int left = 0, right = nums.size() - 1, target_index = k - 1;
        while (true) {
            int p = partition(nums, left, right);

            if (p == target_index) {
                return nums[p];
            }
            else if (p < target_index) {
                left = p + 1;
            }
            else {
                right = p - 1;
            }
        }
    }

    // "sort" in descending order, right is the index of pivot element
    int partition(vector<int>& nums, int left, int right) {
        // use randomness to avoid O(N^2)
        int random_index = left + rand() % (right - left + 1);
        swap(nums[random_index], nums[right]);

        int pivot = nums[right], index = left;

        for (int j = left; j < right; ++j) {
            // if the number is larger, swap it to the front of the vector
            if (nums[j] > pivot) {
                swap(nums[index], nums[j]);
                ++index;
            }
        }
        swap(nums[index], nums[right]);
        return index;
    }
};