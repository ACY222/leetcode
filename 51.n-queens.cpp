// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
  vector<vector<int>> res;
  vector<vector<string>> finalRes;

  bool isValid(const vector<int>& nums, int row, int col) {
    for (int _row = 0; _row < row; ++_row) {
      int _col = nums[_row];
      if (_col == col or _row + _col == row + col or _row - _col == row - col) {
        return false;
      }
    }
    return true;
  }

  void backtrack(vector<int>& nums, int row, int n) {
    if (row == n) {
      res.push_back(nums);
    }

    for (int col = 0; col < n; ++ col) {
      if (isValid(nums, row, col)) {
        nums.push_back(col);
        backtrack(nums, row + 1, n);
        nums.pop_back();
      }
    }
  }

  void convertToString(int n) {
    for (const vector<int>& singleRes : res) {
      vector<string> singleFinalRes;
      for (const int num : singleRes) {
        string prefix, postfix;
        if (num == 0) {
          prefix = "";
          postfix = string(n - 1, '.');
        }
        else if (num == n - 1) {
          prefix = string(n - 1, '.');
          postfix = "";
        }
        else {
          prefix = string(num, '.');
          postfix = string(n - num - 1, '.');
        }
        singleFinalRes.push_back(prefix + "Q" + postfix);
      }
      finalRes.push_back(singleFinalRes);
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<int> nums;
    backtrack(nums, 0, n);
    convertToString(n);
    return finalRes;
  }
};
// @leet end
