// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn minimum_index(nums: Vec<i32>) -> i32 {
        let mut candidate = 0;
        let mut count = 0;

        for &num in &nums {
            if count == 0 {
                candidate = num;
                count = 1;
            } else if candidate == num {
                count += 1;
            } else {
                count -= 1;
            }
        }

        let total = nums.iter().filter(|&&num| num == candidate).count();

        let mut left_count = 0;
        let n = nums.len();

        for i in 0..n - 1 {
            if nums[i] == candidate {
                left_count += 1;
            }

            let right_count = total - left_count;
            if left_count * 2 > i + 1 && right_count * 2 > n - 1 - i {
                return i as i32;
            }
        }

        -1
    }
}
// @leet end
