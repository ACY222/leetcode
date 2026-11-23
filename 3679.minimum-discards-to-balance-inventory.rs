// @leet start
use std::collections::{HashMap, VecDeque};
impl Solution {
    pub fn min_arrivals_to_discard(arrivals: Vec<i32>, w: i32, m: i32) -> i32 {
        let mut num_to_discard = 0;
        let w = w as usize;
        let n = arrivals.len();
        let mut freq = HashMap::new();
        let mut discarded_indices = VecDeque::new();
        for i in 0..n {
            // try to remove last element
            if i >= w {
                // 0 cannot be discarded unless m == 0
                if i - w == *discarded_indices.front().unwrap_or(&n) {
                    discarded_indices.pop_front();
                } else {
                    freq.entry(arrivals[i - w]).and_modify(|e| *e -= 1);
                }
            }

            let entry = freq.entry(arrivals[i]).or_insert(0);
            if *entry == m {
                num_to_discard += 1;
                discarded_indices.push_back(i);
            } else {
                *entry += 1;
            }
        }

        num_to_discard
    }
}
// @leet end
