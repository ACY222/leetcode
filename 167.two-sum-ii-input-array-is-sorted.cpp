// @leet start
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int first {0}, second {1};
    unordered_map<int, int> numToIndex { {numbers[0], 0} };
    while (second < numbers.size()) {
      // if the number at position second is new
      if (numbers[second] != numbers[first]) {
        // try to find another part in the map
        auto iter = numToIndex.find(target - numbers[second]);
        // if we can find, return two indices
        if (iter != numToIndex.end()) {
          return {iter->second + 1, second + 1};
        }
        // and then insert new value into the map, and update first
        numToIndex.insert({numbers[second], second});
        first = second;
      }
      ++second;
    }
    return {};
  }
};
// @leet end
