// @leet start
impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut diff = vec![0; n];
        let prefix_sum = get_prefix_sum(&nums);

        diff[0] = prefix_sum[n - 1] - prefix_sum[0];
        if n >= 2 {
            diff[n - 1] = prefix_sum[n - 2];
        }
        for idx in 1..n - 1 {
            diff[idx] = (prefix_sum[n - 1] - prefix_sum[idx] - prefix_sum[idx - 1]).abs();
        }

        diff
    }
}

fn get_prefix_sum(nums: &[i32]) -> Vec<i32> {
    let mut prefix_sum = vec![0; nums.len()];
    prefix_sum[0] = nums[0];

    for idx in 1..nums.len() {
        prefix_sum[idx] = prefix_sum[idx - 1] + nums[idx];
    }

    prefix_sum
}
// @leet end
