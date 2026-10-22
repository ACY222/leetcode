// @leet start
impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let mut left_sum = 0;
        let mut right_sum: i32 = nums[1..].iter().sum();
        let mut idx = 0;

        while left_sum != right_sum && idx < nums.len() - 1 {
            left_sum += nums[idx];
            idx += 1;
            right_sum -= nums[idx];
        }

        return if left_sum == right_sum {
            idx as i32
        } else {
            -1
        };
    }
}
// @leet end
