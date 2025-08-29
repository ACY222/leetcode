// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>

using std::unordered_set;

class Solution {
public:
  bool hasCycle(ListNode *head) {
    // record the listnode we find
    unordered_set<ListNode*> nodeWeFound {};
    ListNode *p {head};
    while (p != nullptr) {
      // set compares them by their memory
      // address, so it won't use their val and next pointers.
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
