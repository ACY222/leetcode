// @leet start
impl Solution {
    pub fn check_possibility(nums: Vec<i32>) -> bool {
        let mut no_decreasing = true;
        let mut nums = nums;
        let n = nums.len();

        for i in 0..n - 1 {
            if nums[i] > nums[i + 1] {
                if no_decreasing {
                    no_decreasing = false;
                    if i == 0 || nums[i + 1] >= nums[i - 1]{
                        continue;
                    } else {
                        nums[i + 1] = nums[i];
                    }
                } else {
                    return false;
                }
            }

        }

        true
    }
}
// @leet end
