// @leet start
impl Solution {
    pub fn max_score(a: Vec<i32>, b: Vec<i32>) -> i64 {
        let n = b.len();
        // dp[i][j] = max scores earned in a[..i], b[..j]
        let mut dp = vec![vec![0; n]; 5];
        for i in 1..5 {
            dp[i][i - 1] =
                a[i - 1] as i64 * b[i - 1] as i64 + if i == 1 { 0 } else { dp[i - 1][i - 2] };
            for j in i..n {
                dp[i][j] = i64::max(
                    dp[i][j - 1],
                    dp[i - 1][j - 1] + a[i - 1] as i64 * b[j] as i64,
                );
            }
        }

        dp[4][n - 1]
    }
}
// @leet end
