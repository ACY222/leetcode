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
  ListNode* partition(ListNode* head, int x) {
    // dummy1 is the pseudo-head for the values less than x
    // dummy2 is for the values >= x
    ListNode dummy1(-1), dummy2(-1);
    ListNode *p1 {&dummy1}, *p2 {&dummy2}, *p {head};
    while (p != nullptr) {
      if (p->val < x) {
        p1->next = p;
        p1 = p1->next;
      }
      else {
        p2->next = p;
        p2 = p2->next;
      }
      p = p->next;
    }
    p1->next = dummy2.next;
    p2->next = nullptr;
    return dummy1.next;
  }
};
// @leet end
