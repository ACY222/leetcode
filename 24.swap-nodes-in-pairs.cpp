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
        auto curr {head};
        auto prev {head};

        // if we have two nodes to swap
        while (curr != nullptr and curr->next != nullptr) {
            auto next {curr->next};

            // swap curr and next
            curr->next = next->next;
            next->next = curr;

            if (prev == head) {
                head = next;
            } else {
                prev->next = next;
            }
            prev = curr;
            // step forward
            curr = curr->next;
        }

        return head;
    }
};
// @leet end
