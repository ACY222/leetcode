// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     // constructors
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // use tail to remove the leading zero node
    ListNode *l3 { new ListNode() }, *head {l3}, *tail;
    int digit {0}, carry {0};
    // if both of them have digit
    while (l1 != nullptr && l2 != nullptr) {
      digit = l1->val + l2->val + carry;
      l3->val = digit % 10, l3->next = new ListNode();
      carry = digit / 10;
      // move the pointers
      tail = l3;
      l1 = l1->next, l2 = l2->next, l3 = l3->next;
    }
    // now at most one of them has digit
    ListNode *notNullptr = nullptr;
    if (l1 != nullptr) {
      notNullptr = l1;
    }
    else if (l2 != nullptr) {
      notNullptr = l2;
    }
    while (notNullptr != nullptr) {
      digit = notNullptr->val + carry;
      l3->val = digit % 10, l3->next = new ListNode();
      carry = digit / 10;
      // move the pointers
      tail = l3;
      notNullptr = notNullptr->next, l3 = l3->next;
    }
    // remove the leading zero
    if (carry) {
      l3->val = 1;
    }
    else {
      tail->next = nullptr;
    }
    return head;
  }
};
// @leet end
