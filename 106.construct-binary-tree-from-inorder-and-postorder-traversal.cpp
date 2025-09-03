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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n {(int)inorder.size()};
    for (int i = 0; i < n; ++i) {
      valueToIndex[inorder[i]] = i;
    }
    return build(postorder, 0, n, inorder, 0, n);
  }

private:
  // input the postorder and the pos of current root, and the range(begin and
  // end) of inorder
  // return the root of an organized subtree
  TreeNode* build(vector<int>& postorder, int postBegin, int postEnd,
                  vector<int>& inorder, int inBegin, int inEnd) {
    if (inBegin >= inEnd) {
      return nullptr;
    }
    /* post: lllrrrm
     * in  : lllmrrr
     *
     */
    int rootValue {postorder[postEnd - 1]}, index {valueToIndex[rootValue]};
    int leftSize {index - inBegin};
    TreeNode* root = new TreeNode(rootValue);
    // build the tree recursively
    root->left = build(postorder, postBegin, postBegin + leftSize, inorder, inBegin, index);
    root->right = build(postorder, postBegin + leftSize, postEnd - 1, inorder, index + 1, inEnd);
    return root;
  }
};
// @leet end
