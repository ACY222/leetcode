// @leet start
impl Solution {
    pub fn max_sum_range_query(nums: Vec<i32>, requests: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut diff = vec![0; n];

        for req in requests {
            let start = req[0] as usize;
            let end = req[1] as usize;

            diff[start] += 1;
            if end < n - 1 {
                diff[end + 1] -= 1;
            }
        }

        for i in 1..diff.len() {
            diff[i] += diff[i - 1];
        }

        diff.sort_unstable();
        let mut nums = nums;
        nums.sort_unstable();

        let mut sum: u64 = 0;
        const MOD: u64 = 1_000_000_007;
        for i in 0..n {
            sum = (sum + (diff[i] as u64 * nums[i] as u64 % MOD)) % MOD;
        }

        sum as i32
    }
}
// @leet end
