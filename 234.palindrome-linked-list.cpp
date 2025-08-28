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
  // in O(n) time and O(n) space, how to improve it
  // we can reverse the back half linked list, and compare them from both sides
  bool isPalindrome(ListNode* head) {
    ListNode *fast { head }, *slow { head }, *prev, *temp;
    // move fast to the end to find the node in the middle
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // 1, 2, 3, 4, 5
    //       |
    // 1, 2, 3, 4
    //       |
    prev = slow;
    slow = slow->next;
    prev->next = nullptr;
    // 1, 2, 3, 4, 5
    //       p  s
    // 1, 2, 3, 4
    //       p  s
    // begin to reverse the back half linked list
    while (slow) {
      temp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = temp;
    }
    // after reversing the list, compare the node's val from both side
    ListNode *begin { head }, *end { prev };
    while (end) {
      if (begin->val != end->val) {
        return false;
      }
      begin = begin->next;
      end = end->next;
    }
    return true;
  }
};
// @leet end
