// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn find_intersection_values(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut freq1 = HashMap::with_capacity(nums1.len() / 2);
        let mut freq2 = HashMap::with_capacity(nums2.len() / 2);

        let mut res = vec![0, 0];

        for num in nums1 {
            *freq1.entry(num).or_insert(0) += 1;
        }

        for num in nums2 {
            *freq2.entry(num).or_insert(0) += 1;
        }

        for (&num, &count1) in freq2.iter() {
            if let Some(&count2) = freq1.get(&num) {
                res[0] += count2;
                res[1] += count1;
            }
        }

        res
    }
}
// @leet end
