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
  ListNode* reverseList(ListNode* head) {
    // if there is only 1/2 nodes in the list, no need to reverse
    if (!head || !head->next) {
      return head;
    }
    ListNode *curr {head->next}, *prev {head}, *temp {nullptr};
    head->next = nullptr; // to avoid circle in the list
    while (curr) {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }
};
// @leet end
