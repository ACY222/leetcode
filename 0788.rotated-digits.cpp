// @leet start
class Solution {
public:
    // invalid digits: 3, 4, 7, 8
    // 0, 1, 8
    // 2 <-> 5, 6 <-> 9
    int rotatedDigits(int n) { // 1 <= n <= 10000
        // array<int, 10> map {{0, 1, 5, -1, -1, 2, 9, -1, -1, 6}};
        int count = 0;
        // 1 is invalid
        for (int curr_num = 2; curr_num <= n; ++curr_num) {
            // 0: we need a different digit to become 1
            // 1: we'll get a valid number if no invalid digit
            // 2: invalid
            int flag = 0, num = curr_num;
            while (num > 0) {
                int last_digit = num % 10;
                num /= 10;

                switch (last_digit) {
                    // remain the same
                    case 0:
                    case 1:
                    case 8:
                        // do nothing
                        break;

                    // get a different digit
                    case 2:
                    case 5:
                    case 6:
                    case 9:  flag = 1; break;

                    // invalid
                    default: flag = 2; break;
                }

                if (flag == 2) { break; }
            }

            switch (flag) {
                case 1: ++count; break;
                case 0:
                case 2: break;
            }
        }
        return count;
    }
};
// @leet end
