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

#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

class Solution {
public:
  // using priority queue to find the min value of the head
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }
    ListNode *dummy { new ListNode(-1) }, *p { dummy };
    // small root heap
    auto compare_func = [](ListNode* a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare_func)>
      pq(compare_func);
    for (auto head : lists) {
      if (head != nullptr) {
        pq.push(head);
      }
    }
    while (!pq.empty()) {
      ListNode *node { pq.top() };
      pq.pop();
      p->next = node;
      p = p->next;
      if (node->next != nullptr) {
        pq.push(node->next);
      }
    }
    return dummy->next;
  }
};
// @leet end
