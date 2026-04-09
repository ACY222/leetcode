// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head or !head->next) {
            return head;
        }

        auto curr {head};
        auto next {head->next};
        head = next;

        // if we have two nodes to swap
        while (curr and curr->next) {
            if (next != curr->next) {
                next->next = curr->next;
            }

            next = curr->next;

            // swap curr and next
            curr->next = next->next;
            next->next = curr;

            // step forward
            next = curr;
            curr = curr->next;
        }

        return head;
    }
};
// @leet end
