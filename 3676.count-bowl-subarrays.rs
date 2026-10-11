// @leet start
impl Solution {
    pub fn bowl_subarrays(nums: Vec<i32>) -> i64 {
        let mut count = 0;
        for i in 0..nums.len() - 2 {
            let mut min;
            let mut max = nums[i + 1];
            for j in i + 2..nums.len() {
                min = i32::min(nums[i], nums[j]);
                max = max.max(nums[j - 1]);

                if min > max {
                    count += 1;
                }
            }
        }

        count
    }
}
// @leet end
