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
  // Use recursion: input a node head, reverse the linked list start at head and
  // return the head of the reversed list
  ListNode* reverseList(ListNode* head) {
    // If there are only 1/2 nodes in the list, we don't need to reverse
    if (!head || !head->next) {
      return head;
    }
    ListNode *last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
  }
};
// @leet end
