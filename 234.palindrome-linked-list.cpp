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
  // method 1: push the nodes into a stack, and then compare them one by one
  //  O(n) space and O(n) time
  // method 2: reverse the second half of the list, and compare two parts
  bool isPalindrome(ListNode* head) {
    if (!head->next) {
      return true;
    }
    ListNode *slow {head}, *fast {head}, *left {head}, *right;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast) {   // if the length is odd, we need to move slow forward
      slow = slow->next;
    }
    right = reverse(slow);
    while (right) {
      if (left->val != right->val) {
        return false;
      }
      right = right->next;
      left = left->next;
    }
    return true;
  }
private:
  ListNode* reverse(ListNode *head) {
    ListNode *prev {nullptr}, *curr {head}, *next;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
// @leet end
