// @leet start
impl Solution {
    pub fn final_element(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        nums[0].max(nums[n - 1])
    }
}
// @leet end
// 9 4 3 1 7 8 2
