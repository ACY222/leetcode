// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    // return max(abs(i - j)) where colors[i] != colors[j]
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors.front() != colors.back()) { return n - 1; }

        int left = 1, right = n - 2;
        while (colors.front() == colors[left]) {
            ++left;
        }
        while (colors.back() == colors[right]) {
            --right;
        }

        return max(max(left, n - 1 - left), max(right, n - 1 - right));
    }
};
// @leet end
