// @leet start
#include <cstdint>
class Solution {
public:
    // [num1, num2], num_i in [1, 10^15]
    long long totalWaviness(long long num1, long long num2) {
        long long waviness = 0;
        for (long long curr_num = num1; curr_num <= num2; ++curr_num) {
            long long num = curr_num;
            int8_t prev = num % 10, curr = 0;
            enum State { Peak, Valley, Else };
            State state = State::Else;

            while (num >= 10) {
                num /= 10;
                curr = num % 10;

                switch (state) {
                    case State::Peak:
                        if (prev > curr) {
                            ++waviness;
                            state = State::Valley;
                        } else if (prev == curr) {
                            state = State::Else;
                        }
                        break;
                    case State::Valley:
                        if (prev < curr) {
                            ++waviness;
                            state = State::Peak;
                        } else if (prev == curr) {
                            state = State::Else;
                        }
                        break;
                    case State::Else:
                        if (curr > prev) {
                            state = State::Peak;
                        } else if (curr < prev) {
                            state = State::Valley;
                        }
                        break;
                }
                prev = curr;
            }
        }

        return waviness;
    }
};
// @leet end
