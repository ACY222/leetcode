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
using std::vector;
class Solution {
public:
  int count {0};
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return traverse(preorder, inorder.begin(), inorder.end());
  }

private:
  using iter = vector<int>::iterator;
  // input preorder and inorder(its begin and end iterator)
  // return the root of a organized tree
  TreeNode* traverse(vector<int>& preorder, const iter begin, const iter end) {
    if (begin == end) {
      return nullptr;
    }
    TreeNode *curr = new TreeNode(preorder[count++]);
    iter it;
    for (it = begin; it != end; ++it) {
      if (*it == curr->val) {
        break;
      }
    }
    TreeNode* left = traverse(preorder, begin, it);
    TreeNode* right = traverse(preorder, it + 1, end);

    curr->left = left;
    curr->right = right;
    return curr;
  }
};
// @leet end
