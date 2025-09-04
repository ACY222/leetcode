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
#include <iostream>
using std::endl, std::cout;
using std::vector, std::unordered_map;
class Solution {
public:
  // postorder: left -> right -> root
  // preorder : root -> left -> right
  unordered_map<int, int> valueToIndex {};
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size();
    for (int i = 0; i < n; ++i) {
      valueToIndex[preorder[i]] = i;
    }
    return build(preorder, 0, n, postorder, 0, n);
  }
private:
  TreeNode* build(vector<int>& preorder, int preBegin, int preEnd,
                  vector<int>& postorder, int postBegin, int postEnd) {
    if (preBegin >= preEnd) {
      return nullptr;
    }
    int rootValue {postorder[postEnd - 1]};
    TreeNode* root = new TreeNode(rootValue);
    if (postEnd - postBegin >= 2) {
      int index {valueToIndex[postorder[postEnd - 2]]}, leftSize {index - 1 - preBegin};
      root->left = build(preorder, preBegin + 1, index, postorder, postBegin, postBegin + leftSize);
      root->right = build(preorder, index, preEnd, postorder, postBegin + leftSize, postEnd - 1);

    }
    return root;
  }
};
// @leet end
