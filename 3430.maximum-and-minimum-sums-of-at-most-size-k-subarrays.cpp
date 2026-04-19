// @leet start
#include <stack>
#include <vector>
using namespace std;
class Solution {
private:
    long long count_pairs(long long L, long long R, long long k) {
        auto M = k + 1;
        return T(M - 1) - T(M - 1 - L) - T(M - 1 - R) + T(M - 1 - L - R);
    }

    long long T(long long x) {
        if (x <= 0) { return 0; }
        return (1 + x) * x / 2;
    }

public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        long long total_sum = 0;
        int n = nums.size();
        stack<int> st_max, st_min;

        // find the strictly larger element in the left
        for (int i = 0; i <= n; ++i) {
            // if prev <= curr, then right_max[prev] should be curr
            while (!st_max.empty()
                   and (i == n or nums[st_max.top()] <= nums[i])) {
                int curr = st_max.top();
                st_max.pop();
                long long L = curr - (st_max.empty() ? -1 : st_max.top());
                long long R = i - curr;
                total_sum += (long long)nums[curr] * count_pairs(L, R, k);
            }

            if (i < n) st_max.push(i);

            while (!st_min.empty()
                   and (i == n or nums[st_min.top()] >= nums[i])) {
                int curr = st_min.top();
                st_min.pop();
                long long L = curr - (st_min.empty() ? -1 : st_min.top());
                long long R = i - curr;
                total_sum += (long long)nums[curr] * count_pairs(L, R, k);
            }

            if (i < n) st_min.push(i);
        }

        return total_sum;
    }
};
// @leet end
