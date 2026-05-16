// @leet start
class Solution {
private:
    inline int get_next(int curr) {
        int next = 0;
        while (curr) {
            int digit = curr % 10;
            curr /= 10;
            next += digit * digit;
        }
        return next;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = get_next(n);
        while (fast != 1 and slow != fast) {
            // can we memorize the list to reduce computation complexity?
            slow = get_next(slow);
            fast = get_next(get_next(fast));
        }

        return fast == 1;
    }
};
// @leet end
