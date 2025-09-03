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
using std::max, std::unordered_map, std::max_element;
class Solution {
public:
  // use the map so that we can calculate the depth of each node only once
  unordered_map<TreeNode*, int> nodeToDepth {}, nodeToDiameter {};
  int maxDiameter {0};
  // input a root node, output maxDepth(root->left) + maxDepth(root->right)
  int diameterOfBinaryTree(TreeNode* root) {
    maxDepth(root);
    return maxDiameter;
  }
private:
  // return the maxDepth of the tree with root "root"
  int maxDepth(TreeNode* root) {
    if (!root) {    // base case, if root == nullptr
      return 0;
    }
    // if we have already known the depth of root, return it
    if (nodeToDepth.count(root)) {
      return nodeToDepth[root];
    }
    // after following code, nodeToDepth[root->left], nodeToDepth[root->right] are known
    nodeToDepth[root] = 1 + max(maxDepth(root->left), maxDepth(root->right));
    nodeToDiameter[root] = nodeToDepth[root->left] + nodeToDepth[root->right];
    maxDiameter = max(maxDiameter, nodeToDiameter[root]);
    return nodeToDepth[root];
  }
};
// @leet end
