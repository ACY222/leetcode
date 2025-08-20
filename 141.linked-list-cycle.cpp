// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <set>

using std::set;

class Solution {
public:
  bool hasCycle(ListNode *head) {
    // record the listnode we find
    set<ListNode*> nodeWeFound {};
    ListNode *p {head};
    while (p != nullptr) {
      // if we have found this node before
      // we find it twice so there must be cycles
      // but how to compare two node? by their val and next?
      // then how to compare the next
      // countless recursion!
      if (nodeWeFound.count(p)) {
        return true;
      }
      nodeWeFound.insert(p);
      p = p->next;
    }
    return false;
  }
};
// @leet end
