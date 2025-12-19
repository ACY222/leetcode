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
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if (!curr) {
                res.append("# ");
            }
            else {
                res.append(to_string(curr->val) + " ");
                st.push(curr->right);
                st.push(curr->left);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens {split(data)};
        return constructFromPreorder(tokens);
    }

private:
    int index = 0;
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
    vector<string> split(string input) {
        vector<string> tokens;
        string token;
        stringstream ss(input);

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
