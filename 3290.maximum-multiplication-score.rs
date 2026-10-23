// @leet start
impl Solution {
    pub fn max_score(a: Vec<i32>, b: Vec<i32>) -> i64 {
        let mut dp = vec![i64::MIN / 2; 4];

        for &num in &b {
            for i in (0..4).rev() {
                let prev = if i > 0 { dp[i - 1] } else { 0 };
                let curr = prev + a[i] as i64 * num as i64;
                dp[i] = dp[i].max(curr);
            }
        }

        dp[3]
    }
}
// @leet end
