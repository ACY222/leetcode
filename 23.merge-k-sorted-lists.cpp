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

#include <vector>

using std::vector;

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 1) {
      return lists[0];
    }
    ListNode *res { nullptr };
    for (int i = 0; i < lists.size(); ++i) {
      res = mergeTwoLists(res, lists[i]);
    }
    return res;
  }
private:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(-1), *p {&dummy};
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
    return dummy.next;
  }
};
// @leet end
