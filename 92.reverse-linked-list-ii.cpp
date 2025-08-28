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
#include <stack>
using std::stack;
class Solution {
public:
  // using a stack
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // if there is only one node or left == right, no need to reverse
    if (!head->next || left == right) {
      return head;
    }
    ListNode dummy(0, head);    // use a virtual head node to solve edge case
    ListNode *prev { &dummy }, *curr;
    stack<ListNode*> st;
    for (int i = 0; i < left - 1; ++i) {
      prev = prev->next;
    }
    curr = prev->next;
    // now curr points to the first node in the range
    // and prev points to the last node before the range
    for (int i = 0; i <= right - left; ++i) {
      st.push(curr);
      curr = curr->next;
    }
    // now curr points to the first node after the range
    while (!st.empty()) {
      prev->next = st.top();
      st.pop();
      prev = prev->next;
    }
    prev->next = curr;
    return dummy.next;
  }
};
// @leet end
