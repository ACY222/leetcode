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
#include <vector>
using std::vector, std::stack;
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) {
      return {};
    }
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *curr { root };
    while (curr || !st.empty()) {
      while (curr) {    // push the left subtree into the stack
        st.push(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();
      res.push_back(curr->val);
      curr = curr->right;   // cope with the right subtree if it exists
    }
    return res;
  }
};
// @leet end
