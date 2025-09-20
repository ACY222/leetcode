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
using namespace std;

class CBTInserter {
private:
    TreeNode* root;

public:
    // "root" is the root of the complete binary tree
    CBTInserter(TreeNode* root) {
        this->root = root;
    }

    // insert a treenode into the tree so that the tree remains complete,
    // return the value of the parent of the inserted treenode
    int insert(int val) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr {q.front()};
            q.pop();

            if (curr->left) {
                q.push(curr->left);
            }
            else {
                curr->left = new TreeNode(val);
                return curr->val;
            }
            if (curr->right) {
                q.push(curr->right);
            }
            else {
                curr->right = new TreeNode(val);
                return curr->val;
            }
        }
        return -1;
    }

    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @leet end
