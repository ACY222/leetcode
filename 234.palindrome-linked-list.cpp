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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <stack>
using std::stack;
class Solution {
public:
  // in O(n) time and O(n) space, how to improve it
  // Note that the node.val is in [0, 9], we can store it as a digit of int
  // But the number of nodes is in the range [1, 10^5], MAX_INT = 2.1 * 10^9
  bool isPalindrome(ListNode* head) {
    if (!head->next) {    // if there is only one node, it's always true
      return true;
    }
    stack<int> st;
    ListNode *fast { head }, *slow { head };
    // If head.size is even, then the first half vals are pushed, and fast ==
    // nullptr
    // if it's odd, then the first half(without the middle one) are pushed, and
    // fast != nullptr
    while (fast && fast->next) {
      st.push(slow->val);
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast) {   // if the number of the nodes in list is odd
      // slow need to move forward
      slow = slow->next;
    }
    while (slow) {
      if (slow->val != st.top()) {
        return false;
      }
      slow = slow->next;
      st.pop();
    }
    return true;
  }
};
// @leet end
