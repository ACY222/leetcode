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
  ListNode* reverseKGroup(ListNode* head, int k) {
    // if k == 1 or there's only 1 node, no need to reverse
    if (k == 1 || !head->next) {
      return head;
    }
    int numRemainNodesToReverse {k};
    bool isFirstGroup {true};
    ListNode *curr, *prev, *temp, *checkIfEnoughNodes {head};
    ListNode *begin {head}, *end {nullptr}, *lastEnd {nullptr};
    while (checkIfEnoughNodes) {
      --numRemainNodesToReverse;
      checkIfEnoughNodes = checkIfEnoughNodes->next;
      if (!numRemainNodesToReverse) {    // if there's enough nodes
        end = checkIfEnoughNodes;
        curr = begin->next;
        prev = begin;
        while (curr != end) {
          temp = curr->next;
          curr->next = prev;
          prev = curr;
          curr = temp;
        }
        begin->next = end;
        if (lastEnd) {
          lastEnd->next = prev;
        }
        lastEnd = begin;
        if (isFirstGroup) {
          head = prev;
          isFirstGroup = false;
        }
        // prepare for next round
        numRemainNodesToReverse = k;
        begin = end;
      }
    }
    return head;
  }
};
// @leet end
