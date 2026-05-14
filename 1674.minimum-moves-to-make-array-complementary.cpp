// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    // one move: replace a num in nums with {1, 2, ..., limit}
    // nums[i] in {1, 2, ..., limit}
    int minMoves(vector<int>& nums, int limit) {
        // lower, upper, sum
        // 0: (sum, sum)
        // 1: (lower + 1, lower + limit), (upper + 1, upper + limit)
        //  -> (lower + 1, upper + limit)
        // 2: (2, limit * 2), same for each i
        int n = nums.size(), num_pairs = n / 2;
        vector<int> diff(2 * limit + 2);

        for (int i = 0; i < num_pairs; ++i) {
            auto [lower, upper] = minmax(nums[i], nums[n - 1 - i]);

            // (2, 2 * limit)
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // (lower + 1, upper + limit)
            diff[lower + 1] -= 1;
            diff[upper + limit + 1] += 1;

            // (lower + upper, lower + upper)
            diff[lower + upper] -= 1;
            diff[lower + upper + 1] += 1;
        }

        int curr_move = 0, min_move = n;
        for (int i = 2; i <= 2 * limit; ++i) {
            curr_move += diff[i];
            min_move = min(min_move, curr_move);
        }

        return min_move;
    }
};
// @leet end
