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

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }

private:
    TreeNode* deserializeHelper(const string& data, int& pos) {
        if (pos >= data.size()) {
            return nullptr;
        }

        int commaPos = data.find(',', pos);
        string valStr = data.substr(pos, commaPos - pos);

        pos = commaPos + 1;

        if (valStr == "#") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(valStr));
        node->left = deserializeHelper(data, pos);
        node->right = deserializeHelper(data, pos);
        return node;
    }

    void serializeHelper(TreeNode* root, string& res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @leet end
