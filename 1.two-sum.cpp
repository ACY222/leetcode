// @leet start
#include <vector>
#include <unordered_map>

using std::vector, std::unordered_map;
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // the map is initialized as empty
    unordered_map<int, int> numToIndex {};
    int numsSize = nums.size();
    for (int index = 0; index < numsSize; ++index) {
      int diff = target - nums[index];
      // if we can find diff in the map
      if (numToIndex.count(diff)) {
        return { numToIndex[diff], index };
      }
      // otherwise, append the num into the map
      numToIndex[nums[index]] = index;
    }
    return {};
  }
};
// @leet end
