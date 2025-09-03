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
#include <stack>
using std::stack;
class Solution {
public:
  // like a preorder traverse
  void flatten(TreeNode* root) {
    if (!root) {
      return;
    }
    stack<TreeNode*> st {};
    TreeNode *curr {}, *last {};
    st.push(root);
    while (!st.empty()) {
      curr = st.top();
      st.pop();
      if (last) {
        last->left = nullptr;
        last->right = curr;
      }
      if (curr->right) { st.push(curr->right); }
      if (curr->left) { st.push(curr->left); }
      last = curr;
    }
    last->left = nullptr;
    last->right = nullptr;
  }
};
// @leet end
