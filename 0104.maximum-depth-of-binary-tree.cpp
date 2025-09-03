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
using std::queue;
class Solution {
public:
  // maybe I can use BFS to find the maxDepth
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
