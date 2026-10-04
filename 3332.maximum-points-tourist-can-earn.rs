// @leet start
impl Solution {
    pub fn max_score(
        n: i32,
        k: i32,
        stay_score: Vec<Vec<i32>>,
        travel_score: Vec<Vec<i32>>,
    ) -> i32 {
        let k = k as usize; // k days
        let n = n as usize; // n cities
                            // dp[i][j]: The maximum score you can earn in first i-days when ending at j city
                            // day
        let mut dp = vec![vec![0; n]; k];

        for day in 0..k {
            for dest in 0..n {
                let mut max_score = 0;
                for curr in 0..n {
                    let mut base = 0;
                    if day > 0 {
                        base = dp[day - 1][curr];
                    }

                    let curr_score = base
                        + if curr == dest {
                            stay_score[day][curr]
                        } else {
                            travel_score[curr][dest]
                        };

                    max_score = max_score.max(curr_score);
                }

                dp[day][dest] = max_score;
            }
        }

        dp[k - 1].iter().copied().max().unwrap()
    }
}
// @leet end
