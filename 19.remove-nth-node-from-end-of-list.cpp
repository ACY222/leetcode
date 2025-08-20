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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // we need arrive at the (n+1)th node from the end, and then point to the
    // next next node, so we remove the object node
    ListNode *fast {head}, *slow {head};
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    // remove the 1st node
    if (fast == nullptr) {
      head = head->next;
      return head;
    }
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};
// @leet end
