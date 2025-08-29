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
#include <queue>
using std::vector;
using std::queue;
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    queue<TreeNode *> q;
    vector<vector<int>> res;
    int depth {0};
    q.push(root);
    while (!q.empty()) {
      int size { (int)q.size() };
      res.push_back({});    // push an empty vector in every layer
      for (int i = 0; i < size; ++i) {
        // pop node from the queue and push it into res
        TreeNode *node { q.front() };
        q.pop();
        res[depth].push_back(node->val);
        // push node's children into the queue
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
      ++depth;
    }
    return res;
  }
};
// @leet end
