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
#include <cmath>
using std::pow;
class Solution {
public:
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }
    TreeNode *left {root}, *right {root};
    int leftDepth {0}, rightDepth {0};
    while (left) {
      left = left->left;
      ++leftDepth;
    }
    while (right) {
      right = right->right;
      ++rightDepth;
    }
    // if their depth are the same, it's a full binary tree
    if (leftDepth == rightDepth) {
      return pow(2, leftDepth) - 1;
    }
    else {
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
  }
};
// @leet end
