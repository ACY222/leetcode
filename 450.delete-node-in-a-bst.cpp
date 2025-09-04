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
class Solution {
public:
  // first we can replace the object node with the node which has the greatest
  //  value in the subtree node->left
  // second we can replace it with the node which has the least value in
  //  node->right
  // third we can go up to find the minimal node in parent->right
  bool finish {false};
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
      return nullptr;
    }
    // Remember the tree is a binary search tree
    if (root->val == key) {
      // if root has only 0 or 1 child
      if (!root->right) {
        return root->left;  // maybe it's nullptr
      }
      else if (!root->left) {
        return root->right;
      }
      // root has two children, we can find the minNode in root->right
      TreeNode* minNode = getMin(root->right);
      root->right = deleteNode(root->right, minNode->val);    // minNode has at most one child
      minNode->left = root->left;
      minNode->right = root->right;
      root = minNode;
    }
    else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    }
    else {
      root->right = deleteNode(root->right, key);
    }
    return root;
  }
private:
  TreeNode* getMin(TreeNode* root) {
    while (root->left) {
      root = root->left;
    }
    return root;
  }
};
// @leet end
