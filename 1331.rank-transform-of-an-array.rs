// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        if arr.len() == 0 {
            return arr;
        }

        let mut sorted = arr.clone();
        sorted.sort_unstable();
        sorted.dedup();

        let mut rank_map = HashMap::with_capacity(sorted.len());
        for (idx, &val) in sorted.iter().enumerate() {
            rank_map.insert(val, idx as i32 + 1);
        }

        arr.iter().map(|val| rank_map[val]).collect()
    }
}
// @leet end
