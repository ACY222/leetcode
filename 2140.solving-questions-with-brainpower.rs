// @leet start
impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        // dp[k]: the max pionts you can earn starting at k-th problems
        let mut dp = vec![0i64; n + 1];

        for idx in (0..n).rev() {
            let point = questions[idx][0] as i64;
            let brain_power = questions[idx][1] as usize;

            // if skip question[idx]
            let skip = dp[idx + 1];

            let solve = point + *dp.get(idx + brain_power + 1).unwrap_or(&0);
            dp[idx] = skip.max(solve);
        }

        dp[0]
    }
}
// @leet end
