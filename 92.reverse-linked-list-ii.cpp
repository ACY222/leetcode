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
      prev = head;
      curr = prev->next;
      reverse(nums, curr, prev);
      head->next = curr;
      head = prev;
    }
    else {
      ListNode *begin, *last { head };
      left -= 2;
      while (left > 0) {
        --left;
        last = last->next;
      }
      begin = last->next;
      prev = begin;
      curr = begin->next;
      reverse(nums, curr, prev);
      begin->next = curr;
      last->next = prev;
    }
    return head;
  }
private:
  void reverse(int nums, ListNode* &curr, ListNode* &prev) {
    ListNode *next;
    while (nums) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      --nums;
    }
    return;
  }
};
// @leet end
