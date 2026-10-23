// @leet start
impl Solution {
    pub fn find_missing_elements(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        nums.sort_unstable();
        let n = nums.len();
        let mut missing_elements = Vec::with_capacity((nums[n - 1] - nums[0]) as usize - n + 1);

        for w in nums.windows(2) {
            for x in (w[0] + 1)..w[1] {
                missing_elements.push(x);
            }
        }
        missing_elements
    }
}
// @leet end
