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
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) {
      return head;
    }
    // 1 points to the nodes less than x, and 2 points to the nodes geq than x
    ListNode *left1 {head}, *left2 {head}, *right {head};
    // try to find the first node with val < x
    while (left1 != nullptr && left1->val >= x) {
      left1 = left1->next;
    }
    // try to find the first node with val >= x
    while (left2 != nullptr && left2->val < x) {
      left2 = left2->next;
    }
    // head and head2 point to the beginning of two separate lists
    // if all the elements are less than x or geq to x, just return head
    if (!left1 || !left2) {
      return head;
    }
    // otherwise, if both of them are not nullptr
    head = left1;
    ListNode *head2 = left2;
    while (right != nullptr) {
      if (right != left1 && right != left2) {
        if (right->val < x) {
          left1->next = right;
          left1 = left1->next;
        }
        else {
          left2->next = right;
          left2 = left2->next;
        }
      }
      right = right->next;
    }
    left1->next = head2;
    left2->next = nullptr;
    return head;
  }
};
// @leet end
