// @leet start
impl Solution {
    pub fn min_operations(nums: Vec<i32>, queries: Vec<i32>) -> Vec<i64> {
        let mut nums = nums;
        nums.sort_unstable();
        let n = nums.len();

        let mut prefix_sum = vec![nums[0] as i64; nums.len()];
        for i in 1..nums.len() {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i] as i64;
        }

        let mut operations = Vec::with_capacity(queries.len());

        for query in queries {
            // nums[idx] is the first element >= query
            let idx = nums.partition_point(|&num| num < query);
            let first_half = if idx > 0 {
                idx as i64 * query as i64 - prefix_sum[idx - 1]
            } else {
                0
            };
            let second_half = if idx < n {
                (prefix_sum[n - 1] - if idx > 0 { prefix_sum[idx - 1] } else { 0 })
                    - query as i64 * (n - idx) as i64
            } else {
                0
            };
            operations.push(first_half + second_half);
        }

        operations
    }
}
// @leet end
