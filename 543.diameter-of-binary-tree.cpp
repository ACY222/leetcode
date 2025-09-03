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
#include <queue>
#include <algorithm>
#include <unordered_map>
using std::queue;
using std::max, std::unordered_map;
class Solution {
public:
  // use the map so that we can calculate the depth of each node only once
  unordered_map<TreeNode*, int> nodeToDepth {};
  int maxDistance {0};
  // input a root node, output maxDepth(root->left) + maxDepth(root->right)
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) {
      return 0;
    }
    // I calculated the depth of the children nodes again and again
    maxDistance = max(maxDistance, maxDepth(root->left) + maxDepth(root->right));
    return max(maxDistance, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
  }
private:
  // return the maxDepth of the tree with root "root"
  int maxDepth(TreeNode* root) {
    // if we have already known the depth of root, return it
    if (nodeToDepth.count(root)) {
      return nodeToDepth[root];
    }
    if (!root) {    // base case, if root == nullptr
      return 0;
    }
    nodeToDepth[root] = 1 + max(maxDepth(root->left), maxDepth(root->right));
    return nodeToDepth[root];
  }
};
// @leet end
