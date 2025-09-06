// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <iostream>
using std::string, std::to_string, std::stoi;
using std::stack, std::vector, std::getline, std::stringstream;
using std::cout, std::endl;
class Codec {
public:
  int index {0};
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string res {};
    stack<TreeNode*> st {};
    st.push(root);
    while (!st.empty()) {
      TreeNode* top {st.top()};
      st.pop();
      if (!top) { // if top is nullptr
        res.append("# ");
        continue;
      }
      res.append(to_string(top->val) + ' ');
      st.push(top->right);
      st.push(top->left);
    }
    return res;
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<string> preorder {split(data)};
    return constructFromPreorder(preorder);
  }
private:
  TreeNode* constructFromPreorder(vector<string>& preorder) {
    if (preorder[index] == "#") {
      ++index;
      return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(preorder[index++]));
    root->left = constructFromPreorder(preorder);
    root->right = constructFromPreorder(preorder);
    return root;
  }
  vector<string> split(string s) {
    vector<string> tokens;
    string token;
    stringstream ss(s);
    while (getline(ss, token, ' ')) {
      tokens.push_back(token);
    }
    return tokens;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @leet end
