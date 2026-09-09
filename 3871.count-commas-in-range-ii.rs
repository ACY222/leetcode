// @leet start
use std::cmp::min;
impl Solution {
    pub fn count_commas(n: i64) -> i64 {
        let mut count = 0i64;
        let mut x = 1_000i64;

        while n >= x {
            count += (n - x) + 1;
            x *= 1_000;
        }

        count
    }
}
// @leet end
