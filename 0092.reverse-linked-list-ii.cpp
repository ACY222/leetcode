class Solution {
public:
    // input the head and the range [left, right]
    // return the head of new list with part of it being reversed
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseToNthNode(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
private:
    ListNode* succ {nullptr};

    // input the head and n, reverse the first n nodes, return the head of new list
    ListNode* reverseToNthNode(ListNode* head, int n) {
        if (n == 1) {
            succ = head->next;
            return head;
        }

        ListNode* last = reverseToNthNode(head->next, n - 1);
        head->next->next = head;
        head->next = succ;
        return last;
    }

};