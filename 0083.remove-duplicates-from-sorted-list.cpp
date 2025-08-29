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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *slow {head}, *fast {head ? head->next : head};
    while (fast != nullptr) {
      // if the fast points to a node with duplicated value
      // change the next of slow
      while (fast != nullptr && fast->val == slow->val) {
        fast = fast->next;
      }
      slow->next = fast;
      slow = slow->next;
    }

    return head;
  }
};
// @leet end
