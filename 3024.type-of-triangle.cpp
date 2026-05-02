// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int x = nums[0], y = nums[1], z = nums[2];
        if (x == y) {
            if (y == z) {
                return "equilateral";
            } else if (x + y > z) {
                return "isosceles";
            }
        } else if (x == z and x + z > y) {
            return "isosceles";
        } else if (y == z and y + z > x) {
            return "isosceles";
        } else if (x + y > z and x + z > y and y + z > x) {
            return "scalene";
        }

        return "none";
    }
};
// @leet end
