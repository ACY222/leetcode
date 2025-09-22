// @leet start
class Solution {
private:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }

public:
    // we want to know if there are int m and n so that
    // mx + ny = target
    // And one math solution is: if x and y are integers with greatest
    // common divisor d, then there exists mx + ny = d
    // thus, if target % d == 0, then we can measure water
    bool canMeasureWater(int x, int y, int target) {
        return x + y >= target and target % gcd(x, y) == 0;
    }
};
// @leet end
