// @leet start
use std::collections::HashMap;

impl Solution {
    pub fn count_black_blocks(m: i32, n: i32, coordinates: Vec<Vec<i32>>) -> Vec<i64> {
        let m = m as usize;
        let n = n as usize;
        let mut block_counts = HashMap::with_capacity(coordinates.len() * 4);
        let cols = n - 1;

        for coordinate in coordinates {
            let x = coordinate[0] as usize;
            let y = coordinate[1] as usize;

            if x > 0 && y > 0 {
                *block_counts.entry((x - 1) * cols + y - 1).or_insert(0) += 1;
            }
            if x > 0 && y < n - 1 {
                *block_counts.entry((x - 1) * cols + y).or_insert(0) += 1;
            }
            if x < m - 1 && y > 0 {
                *block_counts.entry(x * cols + y - 1).or_insert(0) += 1;
            }
            if x < m - 1 && y < n - 1 {
                *block_counts.entry(x * cols + y).or_insert(0) += 1;
            }
        }

        let mut res = vec![0; 5];
        for &count in block_counts.values() {
            res[count] += 1;
        }

        res[0] = ((m - 1) * (n - 1)) as i64 - res.iter().sum::<i64>();
        res
    }
}
// @leet end
