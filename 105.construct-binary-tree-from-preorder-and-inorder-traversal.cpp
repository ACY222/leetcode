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
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;
class Solution {
public:
  int count {0};
  unordered_map<int, int> valueToIndex {};
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
      valueToIndex[inorder[i]] = i;
    }
    return traverse(preorder, 0, n);
  }

private:
  using iter = vector<int>::iterator;
  // input preorder and inorder(its begin and end iterator)
  // return the root of a organized tree
  TreeNode* traverse(vector<int>& preorder, int begin, int end) {
    if (begin >= end) {
      return nullptr;
    }
    TreeNode *curr = new TreeNode(preorder[count++]);
    int index {valueToIndex[curr->val]};
    TreeNode* left = traverse(preorder, begin, index);
    TreeNode* right = traverse(preorder, index + 1, end);

    curr->left = left;
    curr->right = right;
    return curr;
  }
};
// @leet end
