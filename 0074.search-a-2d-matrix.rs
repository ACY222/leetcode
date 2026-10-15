// @leet start
use std::cmp::Ordering;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        let len = m * n;

        let mut left = 0;
        let mut right = len - 1;

        while left <= right {
            let idx = (left + right) / 2;
            let i = idx / n;
            let j = idx % n;

            match matrix[i][j].cmp(&target) {
                Ordering::Less => left = idx + 1,
                Ordering::Equal => return true,
                Ordering::Greater => {
                    if idx > 0 {
                        right = idx - 1
                    } else {
                        return false;
                    }
                }
            }
        }

        false
    }
}
// @leet end
