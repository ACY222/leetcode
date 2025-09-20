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
#include <queue>
using namespace std;

class CBTInserter {
private:
    TreeNode* root;
    vector<TreeNode*> nodes;

    void initialize(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            nodes.push_back(curr);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
public:
    CBTInserter(TreeNode* root) : root(root) {
        initialize(root);
    }

    int insert(int val) {
        TreeNode* parent = nodes[(nodes.size() - 1) / 2];
        TreeNode* newNode = new TreeNode(val);
        if (parent->left) {
            parent->right = newNode;
        }
        else {
            parent->left = newNode;
        }
        nodes.push_back(newNode);
        return parent->val;
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @leet end
