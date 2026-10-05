// @leet start
impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        let mut total_num = 0;
        let prefix_sum = get_prefix_sum(&nums);

        for start in 0..nums.len() {
            for end in start..nums.len() {
                let curr_sum = prefix_sum[end] - if start == 0 { 0 } else { prefix_sum[start - 1] };
                if curr_sum == goal {
                    total_num += 1;
                }
            }
        }

        total_num
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
