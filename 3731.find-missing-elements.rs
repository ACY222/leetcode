// @leet start
use std::collections::BTreeSet;
impl Solution {
    pub fn find_missing_elements(nums: Vec<i32>) -> Vec<i32> {
        let set: BTreeSet<i32> = nums.into_iter().collect();
        let &min = set.first().unwrap();
        let &max = set.last().unwrap();

        (min..max).filter(|x| !set.contains(x)).collect()
    }
}
// @leet end
