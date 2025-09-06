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
  // inorder traverse using stack
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* curr {root};
    while (curr or !st.empty()) {
      while (curr) {
        st.push(curr);
        curr = curr->left;
      }
      curr = st.top(); st.pop();
      // do something here, begin:
      --k;
      if (k == 0) {
        return curr->val;
      }
      // end
      curr = curr->right;
    }
    return -1;
  }
};
// @leet end
