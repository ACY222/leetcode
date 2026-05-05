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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 or head == nullptr or head->next == nullptr) { return head; }

        auto last {head};
        int len = 1;
        while (last->next) {
            last = last->next;
            ++len;
        }

        k %= len;

        if (k == 0) { return head; }

        auto fast {head}, slow {head};
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        auto new_head = slow->next;
        slow->next = nullptr;
        last->next = head;

        return new_head;
    }
};
// @leet end
