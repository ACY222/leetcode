// @leet start
impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        // dp[k]: the max pionts you can earn starting at k-th problems
        let mut dp = vec![0i64; n];

        for idx in (0..n).rev() {
            let point = questions[idx][0] as i64;
            let brain_power = questions[idx][1] as usize;

            // if skip question[idx]
            let point1 = if idx < n - 1 { dp[idx + 1] } else { 0 };

            let point2 = point
                + if idx + brain_power + 1 < n {
                    dp[idx + brain_power + 1]
                } else {
                    0
                };

            dp[idx] = point1.max(point2);
        }

        dp[0]
    }
}
// @leet end
