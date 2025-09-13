// @leet start
#include <list>
#include <vector>
using namespace std;
class Solution {
private:
  vector<vector<int>> res;

  void traverse(const vector<int>& nums, list<int>& track, vector<bool>& used) {
    if (track.size() == nums.size()) {
      // convert the list to a vector and push it into res
      res.push_back(vector<int>(track.begin(), track.end()));
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) {
        continue;
      }
      track.push_back(nums[i]);
      used[i] = true;
      traverse(nums, track, used);
      track.pop_back();
      used[i] = false;
    }
  }
public:
  vector<vector<int>> permute(vector<int>& nums) {
    list<int> track;
    vector<bool> used(nums.size(), false);
    traverse(nums, track, used);
    return res;
  }
};
// @leet end
