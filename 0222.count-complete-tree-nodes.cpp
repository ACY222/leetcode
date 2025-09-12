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
    int depth = 0;
    TreeNode* left {root}, *right {root};
    while (left and right) {
      left = left->left;
      right = right->right;
      ++depth;
    }
    if (left == right) {
      return (int)pow(2, depth) - 1;
    }
    else {
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
  }
};
// @leet end
