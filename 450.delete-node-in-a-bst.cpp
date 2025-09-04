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
    if (!root or (root->val == key and !root->left and !root->right)) {
      return nullptr;
    }
    return findNode(nullptr, root, key, false);
  }
private:
  TreeNode* findNode(TreeNode* parent, TreeNode* curr, int key, bool isLeft) {
    if (!curr) {
      return nullptr;
    }
    if (finish) {
      return curr;
    }
    if (curr->val == key) {
      deleteCurrentNode(parent, curr, isLeft);
      return curr;
    }
    if (curr->left) findNode(curr, curr->left, key, true);
    if (curr->right) findNode(curr, curr->right, key, false);
    return curr;
  }
  void deleteCurrentNode(TreeNode* parent, TreeNode* curr, bool isLeft) {
    TreeNode *left {curr->left}, *right {curr->right};
    if (left) {
      TreeNode *maxNode, *parentMaxNode {left};
      // if (left->val != maxValue(curr->left))
      if (parentMaxNode->right) {
        while (parentMaxNode->right->right) {
          parentMaxNode = parentMaxNode->right;
        }
        maxNode = parentMaxNode->right;
        curr->val = maxNode->val;
        parentMaxNode->right = maxNode->left;
      }
      else {
        curr->val = left->val;
        curr->left = left->left;
      }
    }
    else if (right) {
      TreeNode *minNode, *parentMinNode {right};
      // if (left->val != maxValue(curr->left))
      if (parentMinNode->left) {
        while (parentMinNode->left->left) {
          parentMinNode = parentMinNode->left;
        }
        minNode = parentMinNode->left;
        curr->val = minNode->val;
        parentMinNode->left = minNode->right;
      }
      else {
        curr->val = right->val;
        curr->right = right->right;
      }
    }
    // if curr is a leaf, then just remove it from its parent
    else {
      isLeft ? parent->left = nullptr : parent->right = nullptr;
    }
  }
};
// @leet end
