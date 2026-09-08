// @leet start
impl Solution {
    pub fn count_commas(n: i32) -> i32 {
        if n < 1_000 {
            0
        } else {
            n - 999
        }
    }
}
// @leet end
