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
#include <unordered_map>
using std::vector;
using std::unordered_map;
class Solution {
public:
  unordered_map<int, int> valueToIndex {};
  int pos;
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    pos = postorder.size() - 1;
    for (int i = 0; i < n; ++i) {
      valueToIndex[inorder[i]] = i;
    }
    return build(postorder, 0, n);
  }

private:
  // input the postorder and the pos of current root, and the range(begin and
  // end) of inorder
  // return the root of an organized subtree
  TreeNode* build(vector<int>& postorder, int begin, int end) {
    if (begin >= end) {
      return nullptr;
    }
    int rootValue {postorder[pos--]}, index {valueToIndex[rootValue]};
    TreeNode* root = new TreeNode(rootValue);
    // the next root lies in right subtree
    if (pos >= 0 and valueToIndex[postorder[pos]] > index) {
      root->right = build(postorder, index + 1, end);
    }
    // the next root lies in left subtree
    if (pos >= 0 and valueToIndex[postorder[pos]] < index) {
      root->left = build(postorder, begin, index);
    }
    return root;
  }
};
// @leet end
