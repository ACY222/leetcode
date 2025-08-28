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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // if there's only one node or right equals left, no need to reverse
    if (!head->next || right == left) {
      return head;
    }
    ListNode *curr, *prev, *next, *last, *begin { head };
    int nums { right - left };    // the number of nodes to reverse
    if (left == 1) {    // it begins at head
      prev = begin;
      curr = prev->next;
      while (nums) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        --nums;
      }
      begin->next = curr;
      head = prev;
    }
    else {
      left -= 2;
      while (left > 0) {
        --left;
        prev = begin->next;
      }
      last = begin;
      begin = begin->next;
      prev = begin;
      curr = prev->next;
      while (nums) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        --nums;
      }
      last->next = prev;
      begin->next = curr;
    }
    return head;
  }
};
// @leet end
