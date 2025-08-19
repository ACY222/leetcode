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
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode virtualNode(-1), *p {&virtualNode};
    ListNode *p1 = list1, *p2 = list2;
    // if both of them are not nullptr
    while (p1 != nullptr && p2 != nullptr) {
      // link the node with smaller val to p->next
      if (p1->val <= p2->val) {
        p->next = p1;
        p1 = p1->next;
      }
      else {
        p->next = p2;
        p2 = p2->next;
      }
      // move p forward
      p = p->next;
    }
    // now one/two of them are nullptr
    if (p1 != nullptr) {
      p->next = p1;
    }
    if (p2 != nullptr) {
      p->next = p2;
    }
    return virtualNode.next;
  }
};
// @leet end
