// @leet start
#include <array>
#include <string>
using namespace std;
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        constexpr int NUM_LETTERS = 26;
        if (s.size() != t.size()) { return false; }

        int n = s.size();

        int num_loops = k / NUM_LETTERS;
        int num_left = k % NUM_LETTERS;

        array<int, NUM_LETTERS> num_shifts;
        num_shifts.fill(num_loops);

        for (int i = 0; i < num_left; ++i) {
            num_shifts[i]++;
        }

        for (int i = 0; i < n; ++i) {
            int shift = (t[i] - s[i] + 26) % 26 - 1;
            if (shift == -1) { continue; }

            // no available shifts
            if (num_shifts[shift] == 0) { return false; }

            // consume one shift
            num_shifts[shift]--;
        }

        return true;
    }
};
// @leet end
