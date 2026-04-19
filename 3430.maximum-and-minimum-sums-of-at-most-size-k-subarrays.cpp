// @leet start
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

    void devote_as_max(const vector<int>& nums, int k, long long& total_sum) {
        int n = nums.size();
        vector<int> st;
        vector<int> left_max(n, -1), right_max(n, n);

        // find the strictly larger element in the left
        for (int i = 0; i < n; ++i) {
            // pop if prev <= curr
            while (!st.empty() and nums[st.back()] <= nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) { left_max[i] = st.back(); }

            st.push_back(i);
        }

        st.clear();
        // find the larger element in the right
        for (int i = n - 1; i >= 0; --i) {
            // pop if prev < curr
            while (!st.empty() and nums[st.back()] < nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) { right_max[i] = st.back(); }
            st.push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            long long L = i - left_max[i];
            long long R = right_max[i] - i;
            total_sum += (long long)nums[i] * count_pairs(L, R, k);
        }
    }

    void devote_as_min(const vector<int>& nums, int k, long long& total_sum) {
        int n = nums.size();
        vector<int> st;
        vector<int> left_min(n, -1), right_min(n, n);

        // find the strictly smaller element in the left
        for (int i = 0; i < n; ++i) {
            // pop if prev >= curr
            while (!st.empty() and nums[st.back()] >= nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) { left_min[i] = st.back(); }

            st.push_back(i);
        }

        st.clear();
        // find the smaller element in the right
        for (int i = n - 1; i >= 0; --i) {
            // pop if prev > curr
            while (!st.empty() and nums[st.back()] > nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) { right_min[i] = st.back(); }
            st.push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            long long L = i - left_min[i];
            long long R = right_min[i] - i;
            total_sum += (long long)nums[i] * count_pairs(L, R, k);
        }
    }

public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long total_sum = 0;
        devote_as_max(nums, k, total_sum);
        devote_as_min(nums, k, total_sum);

        return total_sum;
    }
};
// @leet end
