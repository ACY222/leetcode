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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) {
      return nullptr;
    }
    ListNode *begin {head}, *end {head}, *newHead;
    for (int i = 0; i < k; ++i) {
      if (!end) {   // if the number of nodes are less than k, no need to reverse
        return head;
      }
      end = end->next;
    }
    newHead = reverse(begin, end);
    begin->next = reverseKGroup(end, k);
    return newHead;
  }
private:
  // reverse the part of the list [begin, end) and return the new head
  ListNode* reverse(ListNode *begin, ListNode *end) {
    ListNode *prev {nullptr}, *curr {begin}, *next {begin};
    while (curr != end) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
// @leet end
