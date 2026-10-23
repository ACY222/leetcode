// @leet start
impl Solution {
    pub fn find_missing_elements(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        nums.sort_unstable();
        let n = nums.len();
        let mut missing_elements = Vec::with_capacity((nums[n - 1] - nums[0]) as usize - n + 1);
        let mut curr = nums[0];
        for &num in &nums[1..] {
            curr += 1;
            missing_elements.extend(curr..num);
            curr = num;
        }

        missing_elements
    }
}
// @leet end
