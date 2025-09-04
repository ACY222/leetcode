// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using std::vector;
class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return buildSubTree(nums, 0, nums.size());
  }
private:
  TreeNode* buildSubTree(vector<int>& nums, int begin, int end) {
    // base case, if the vector is empty
    if (begin >= end) {
      return nullptr;
    }
    // find the index and value of the max number
    int index{0}, rootValue {-1};
    for (int i = begin; i < end; ++i) {
      if (nums[i] > rootValue) {
        rootValue = nums[i];
        index = i;
      }
    }
    TreeNode* root = new TreeNode(rootValue);
    root->left = buildSubTree(nums, begin, index);
    root->right = buildSubTree(nums, index + 1, end);
    return root;
  }
};
// @leet end
