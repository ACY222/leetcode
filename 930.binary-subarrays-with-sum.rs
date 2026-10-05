// @leet start
impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        let mut total_num = 0;
        let prefix_sum = get_prefix_sum(&nums);

        for start in 0..nums.len() {
            let base = if start == 0 { 0 } else { prefix_sum[start - 1] };
            let end = usize::max(start, prefix_sum.partition_point(|&sum| sum - base < goal));

            if end == prefix_sum.len() {
                break;
            }

            total_num += prefix_sum[end..].partition_point(|&sum| sum - base <= goal);
        }

        total_num as i32
    }
}
fn get_prefix_sum(nums: &[i32]) -> Vec<i32> {
    let mut prefix_sum = vec![0; nums.len()];

    prefix_sum[0] = nums[0];

    for i in 1..nums.len() {
        prefix_sum[i] = prefix_sum[i - 1] + nums[i];
    }

    prefix_sum
}
// @leet end
