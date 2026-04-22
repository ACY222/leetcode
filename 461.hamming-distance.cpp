// @leet start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        while (x > 0 or y > 0) {
            int last_x = x % 2;
            int last_y = y % 2;

            if (last_x != last_y) { ++dist; }

            x = x >> 1;
            y = y >> 1;
        }

        return dist;
    }
};
// @leet end
