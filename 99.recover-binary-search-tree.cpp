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
#include <stack>
using namespace std;
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

public:
    void recoverTree(TreeNode *root) {
        TreeNode *first {nullptr}, *second {nullptr}, *curr {root};
        stack<TreeNode *> st;

        while (curr || !st.empty()) {
            // keep pushing left subtrees
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            // Now curr is a leaf, or a parent with only right child
            // But no matter what it is, curr's val comes first
            st.pop();

            if (first == nullptr) {
                first = curr;
            } else {
                // first < curr
                if (first->val < curr->val) {
                    if (second != nullptr) {
                        swap_val(first, second);
                        return;
                    } else {
                        first = curr;
                    }
                }
                // fisrt > curr
                else {
                    // second < curr
                    if (second == nullptr or second->val < curr->val) {
                        second = curr;
                    }
                    // curr < second < first
                    else {
                        second = curr;
                        swap_val(first, second);
                        return;
                    }
                }
            }

            // if curr is a leaf, then next loop we will cope with its parent
            // tree if not, we will cope with its right subtree
            curr = curr->right;
        }

        swap_val(first, second);
    }
};
// @leet end
