// @leet start
use std::cmp::Ordering;
impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        for x in n / 2..=n {
            match (2 * x * x).cmp(&(n * (n + 1))) {
                Ordering::Less => continue,
                Ordering::Equal => return x,
                Ordering::Greater => return -1,
            }
        }

        -1
    }
}
// @leet end
