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
using std::vector, std::unordered_map, std::string, std::to_string;
class Solution {
public:
  unordered_map<string, vector<TreeNode*>> rangeToTrees {};
  vector<TreeNode*> generateTrees(int n) {
    return genetate_trees(1, n);
  }

private:
  vector<TreeNode*> genetate_trees(int begin, int end) {
    string key {to_string(begin) + '-' + to_string(end)};
    if (rangeToTrees.count(key)) {
      return rangeToTrees[key];
    }
    if (begin > end) {
      return {nullptr};
    }
    vector<TreeNode*> trees {};
    for (int rootValue = begin; rootValue <= end; ++rootValue) {
      vector<TreeNode*> leftTrees { genetate_trees(begin, rootValue - 1) };
      vector<TreeNode*> rightTrees { genetate_trees(rootValue + 1, end) };
      for (auto leftTree : leftTrees) {
        for (auto rightTree : rightTrees) {
          TreeNode* root = new TreeNode(rootValue);
          root->left = leftTree;
          root->right = rightTree;
          trees.push_back(root);
        }
      }
    }
    rangeToTrees[key] = trees;
    return trees;
  }
};
// @leet end
