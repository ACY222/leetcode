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
#include <string>
using std::vector;
using std::string, std::to_string, std::unordered_map;
class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    unordered_map<string, vector<TreeNode*>> fromRangeToSubtree {};
    return generate_trees(1, n, fromRangeToSubtree);
  }
private:
  vector<TreeNode*> generate_trees(int start, int end, unordered_map<string, vector<TreeNode*>>& fromRangeToSubtree) {
    string key {to_string(start) + '-' + to_string(end)};
    if (fromRangeToSubtree.find(key) != fromRangeToSubtree.end()) {
      return fromRangeToSubtree[key];
    }
    vector<TreeNode*> trees;
    if (start > end) {
      trees.push_back(nullptr);
    }
    for (int rootVal = start; rootVal <= end; ++rootVal) {
      vector<TreeNode*> leftTrees { generate_trees(start, rootVal - 1, fromRangeToSubtree) };
      vector<TreeNode*> rightTrees { generate_trees(rootVal + 1, end, fromRangeToSubtree) };
      for (auto left : leftTrees) {
        for (auto right : rightTrees) {
          TreeNode* root = new TreeNode(rootVal);
          root->left = left;
          root->right = right;
          trees.push_back(root);
        }
      }
    }
    return trees;
  }
};
// @leet end
