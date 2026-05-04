// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        const int LOOP_SIZE = 26;
        if (s.size() != t.size()) { return false; }

        int n = s.size();

        int num_loops = k / LOOP_SIZE;
        int num_left = k % LOOP_SIZE;

        vector<int> num_shifts;

        num_shifts.resize(LOOP_SIZE, num_loops);

        for (int i = 0; i < num_left; ++i) {
            num_shifts[i]++;
        }

        for (int i = 0; i < n; ++i) {
            int shift = (t[i] - s[i] + 26) % 26;
            if (shift == 0) { continue; }
            shift--;

            // no available shifts
            if (num_shifts[shift] == 0) { return false; }

            // consume one shift
            num_shifts[shift]--;
        }

        return true;
    }
};
// @leet end
