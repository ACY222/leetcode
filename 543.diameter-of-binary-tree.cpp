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
#include <algorithm>
using std::max;
class Solution {
public:
  // use the map so that we can calculate the depth of each node only once
  // Actually, I will only access the depth of each node once, so I shouldn't
  // waste the space to do this
  int maxDiameter {0};
  // input a root node, output maxDepth(root->left) + maxDepth(root->right)
  int diameterOfBinaryTree(TreeNode* root) {
    maxDepth(root);
    return maxDiameter;
  }
private:
  // input the current node, return the diameter of it
  int maxDepth(TreeNode* curr) {
    if (!curr) {
      return 0;
    }
    int left {maxDepth(curr->left)}, right {maxDepth(curr->right)};
    maxDiameter = max(maxDiameter, left + right);
    return max(left, right) + 1;
  }
};
// @leet end
