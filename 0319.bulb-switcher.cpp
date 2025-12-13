// @leet start
#include <cmath>
class Solution {
public:
    // the n bulbs are initially off
    // toggle every i-th bulb in the i-th round
    // return the numbers of bulbs which are on after n rounds
    // 2 -> on on -> on off -> 1
    // 3 -> on on on -> on off on -> on off off -> 1
    // 4 -> on on on on -> on off on off -> on off off off ->
    //      on off off on -> 2
    int bulbSwitch(int n) {
        return static_cast<int>(std::sqrt(n));
    }
};
// @leet end
