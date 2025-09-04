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
  // inorder traverse works here
  TreeNode* bstToGst(TreeNode* root) {
    int sum {0}, originalSum {0};
    stack<TreeNode*> st;
    TreeNode* curr {root};
    while (curr or !st.empty()) {
      while (curr) {
        st.push(curr);
        curr = curr->right;
      }
      curr = st.top(); st.pop();
      // do something here, begin:
      originalSum = sum;
      sum += curr->val;
      curr->val += originalSum;
      // end
      curr = curr->left;
    }
    return root;
  }
};
// @leet end
