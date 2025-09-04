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
#include <stack>
using std::vector;
using std::stack;
class Solution {
public:
  // Yeah, I can use monotonic stack to find the max numbers in O(n) time
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int n {(int)nums.size()};
    vector<int> right {rightGreater(nums, n)}, left {leftGreater(nums, n)};
    // initialize the nodes for each number
    vector<TreeNode*> nodes;
    TreeNode* root {nullptr};
    for (int i = 0; i < n; ++i) {
      nodes.push_back(new TreeNode(nums[i]));
    }
    for (int i = 0; i < n; ++i) {
      // if there's no nodes with greater value in both sides
      if (right[i] == -1 and left[i] == -1) {
        root = nodes[i];
      }
      // if there's no node with greater value in the left
      // or if rightGreater's value > leftGreater's value
      else if (left[i] == -1 or (right[i] != -1 and nums[left[i]] > nums[right[i]])) {
        nodes[right[i]]->left = nodes[i];
      }
      else {
        nodes[left[i]]->right = nodes[i];
      }
    }
    return root;
  }
private:
  vector<int> rightGreater(vector<int>& nums, int n) {
    vector<int> indexOfRightGreater(n, -1);
    stack<int> st {};   // the contents of the stack are the indices
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() and nums[st.top()] < nums[i]) {
        st.pop();
      }
      if (!st.empty()) {
        indexOfRightGreater[i] = st.top();
      }
      st.push(i);
    }
    return indexOfRightGreater;
  }

  vector<int> leftGreater(vector<int>& nums, int n) {
    vector<int> indexOfLeftGreater(n, -1);
    stack<int> st {};
    for (int i = 0; i < n; ++i) {
      while (!st.empty() and nums[st.top()] < nums[i]) {
        st.pop();
      }
      if (!st.empty()) {
        indexOfLeftGreater[i] = st.top();
      }
      st.push(i);
    }
    return indexOfLeftGreater;
  }
};
// @leet end
