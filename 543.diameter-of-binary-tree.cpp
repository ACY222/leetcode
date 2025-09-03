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
#include <queue>
#include <algorithm>
using std::queue;
using std::max;
class Solution {
public:
  int maxDistance {0};
  // input a root node, output maxDepth(root->left) + maxDepth(root->right)
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) {
      return 0;
    }
    maxDistance = max(maxDistance, maxDepth(root->left) + maxDepth(root->right));
    maxDistance = max(maxDistance, diameterOfBinaryTree(root->left));
    maxDistance = max(maxDistance, diameterOfBinaryTree(root->right));
    return maxDistance;
  }
private:
  // return the maxDepth of the tree with root "root"
  int maxDepth(TreeNode* root) {
    if (!root) {  // base case: if root == nullptr
      return 0;
    }
    queue<TreeNode*> q {};
    int depth {0};
    q.push(root);
    while (!q.empty()) {
      TreeNode* top;
      int size {(int)q.size()};
      ++depth;
      for (int i = 0; i < size; ++i) {
        top = q.front();
        q.pop();
        if (top->left) { q.push(top->left); }
        if (top->right) { q.push(top->right); }
      }
    }
    return depth;
  }
};
// @leet end
