// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn minimum_index(nums: Vec<i32>) -> i32 {
        let mut left_freq = HashMap::new();
        let mut right_freq = HashMap::new();
        let mut last_dom = nums[0];
        let mut curr_dom;
        let mut idx = 0;

        for &num in nums.iter() {
            right_freq
                .entry(num)
                .and_modify(|freq| *freq += 1)
                .or_insert(1);
        }

        while idx < nums.len() - 1 {
            right_freq.entry(nums[idx]).and_modify(|freq| *freq -= 1);
            left_freq
                .entry(nums[idx])
                .and_modify(|freq| *freq += 1)
                .or_insert(1);

            if last_dom != 0 && left_freq[&last_dom] * 2 > idx + 1 {
                curr_dom = last_dom;
            } else if left_freq[&nums[idx]] * 2 > idx + 1 {
                curr_dom = nums[idx];
            } else {
                curr_dom = 0;
            }

            if curr_dom != 0 && right_freq.get(&curr_dom).unwrap_or(&0) * 2 > nums.len() - idx - 1 {
                return idx as i32;
            }

            last_dom = curr_dom;
            idx += 1;
        }
        -1
    }
}
// @leet end
