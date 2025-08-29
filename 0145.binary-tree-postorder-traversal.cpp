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
using std::vector;
using std::stack;
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) {
      return {};
    }
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *prev {};    // points to the previous visited node
    st.push(root);
    while (!st.empty()) {
      TreeNode *curr { st.top() };
      // if curr is a leaf(then nobody comes before it) or prev is its child
      // (there is no its child in the stack), then we can push its val directly
      if ((!curr->left && !curr->right) || (prev && (prev == curr->left || prev == curr->right))) {
        st.pop();
        res.push_back(curr->val);
        prev = curr;
      }
      else {
        if (curr->right) { st.push(curr->right); }
        if (curr->left) { st.push(curr->left); }
      }
    }
    return res;
  }
};
// @leet end
