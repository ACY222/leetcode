// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast {head}, *slow {head};
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {   // there is a cycle
        break;
      }
    }
    // if there is no cycle
    if (fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }
    slow = head;
    // Slow and fast move forward together, and they will meet at the start
    // node.
    // Let's say slow moves k steps in the first loop, then fast moves 2k steps.
    // And the k more steps are all in the cycle, so k is a multiple of the size
    // of loop, and k is also the distance from the head to current position
    // Let's say fast is m steps ahead of the start node, then after k - m
    // steps, fast will arrive at the start node. And we know that after k - m
    // steps, slow will arrive at it too. So they will meet there
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
// @leet end
