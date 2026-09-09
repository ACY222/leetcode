// @leet start
impl Solution {
    pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32 {
        if k == 1 {
            return 0;
        }

        let mut nums = nums;
        let k = k as usize;
        nums.sort_unstable();

        let mut min_diff = i32::MAX;
        for i in (0..=nums.len() - k) {
            min_diff = min_diff.min(nums[i + k - 1] - nums[i]);
        }

        min_diff
    }
}
// @leet end
