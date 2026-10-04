// @leet start
impl Solution {
    pub fn max_score(
        n: i32,
        k: i32,
        stay_score: Vec<Vec<i32>>,
        travel_score: Vec<Vec<i32>>,
    ) -> i32 {
        let days = k as usize; // k days
        let cities = n as usize; // n cities

        // max scores ending at cities j
        let mut dp = vec![0; cities];

        for day in 0..days {
            let mut new_dp = vec![0; cities];

            for dest in 0..cities {
                // stay at dest
                new_dp[dest] = dp[dest] + stay_score[day][dest];

                // travel to dest
                for curr in 0..cities {
                    new_dp[dest] = new_dp[dest].max(dp[curr] + travel_score[curr][dest]);
                }
            }

            dp = new_dp;
        }

        dp.iter().copied().max().unwrap_or(0)
    }
}
// @leet end
