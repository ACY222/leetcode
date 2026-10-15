// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };
class Solution {
private:
    void swap_val(TreeNode *first, TreeNode *second) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

    void detect(TreeNode *prev, TreeNode *curr, TreeNode *& first,
                TreeNode *& second) {
        if (prev and prev->val > curr->val) {
            if (!first) first = prev;
            second = curr;
        }
    }

public:
    void recoverTree(TreeNode *root) {
        TreeNode *first {nullptr}, *second {nullptr}, *curr {root},
            *prev {nullptr};

        while (curr) {
            if (!curr->left) {
                detect(prev, curr, first, second);
                prev = curr;
                curr = curr->right;
            } else {
                auto pred = curr->left;

                while (pred->right and pred->right != curr) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    detect(prev, curr, first, second);
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // 1 3 2
        swap_val(first, second);
    }
};
// @leet end
