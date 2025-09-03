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
  // rotate k times means insert the last k nodes in the beginning
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
      return head;
    }
    ListNode *fast {head}, *slow {head};
    int i;
    for (i = 0; i < k && fast != nullptr; ++i) {
      fast = fast->next;
    }
    if (i != k) {   // the length of the list(i) is less than k
      return rotateRight(head, k % i);
    }
    else if (i == k && fast == nullptr) {   // length == k, nothing todo
      return head;
    }
    // otherwise, length > k
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    // now slow points to the last node before the last k nodes, fast points to
    // the last node in the whole list
    ListNode *newHead = slow->next;
    slow->next = nullptr;
    fast->next = head;
    return newHead;
  }
};
// @leet end
