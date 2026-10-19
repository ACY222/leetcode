// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn find_intersection_values(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut freqs = HashMap::with_capacity(nums1.len() / 2);
        let mut res = vec![0, 0];

        for num in nums1 {
            freqs
                .entry(num)
                .or_insert(Freq { freq1: 0, freq2: 0 })
                .freq1 += 1;
        }

        for num in nums2 {
            freqs
                .entry(num)
                .or_insert(Freq { freq1: 0, freq2: 0 })
                .freq2 += 1;
        }

        for &Freq { freq1, freq2 } in freqs.values() {
            if freq1 != 0 && freq2 != 0 {
                res[0] += freq1 as i32;
                res[1] += freq2 as i32;
            }
        }

        res
    }
}

struct Freq {
    freq1: u8,
    freq2: u8,
}
// @leet end
