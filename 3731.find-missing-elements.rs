// @leet start
use std::collections::BTreeSet;
impl Solution {
    pub fn find_missing_elements(nums: Vec<i32>) -> Vec<i32> {
        let mut min = nums[0];
        let mut max = nums[0];
        let mut missing_elements = BTreeSet::new();

        for &num in nums[1..].iter() {
            if num < min {
                missing_elements.extend(num + 1..min);
                min = num;
            } else if num > max {
                missing_elements.extend(max + 1..num);
                max = num;
            } else {
                missing_elements.remove(&num);
            }
        }

        missing_elements.into_iter().collect()
    }
}
// @leet end
