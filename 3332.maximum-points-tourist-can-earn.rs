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
        let mut res = 0;

        let mut dp = vec![vec![-1; cities]; days];

        for day in 0..days {
            for curr in 0..cities {
                res = res.max(
                    stay_score[day][curr]
                        + solve(
                            &stay_score,
                            &travel_score,
                            &mut dp,
                            day + 1,
                            curr,
                            days,
                            cities,
                        ),
                );

                for dest in 0..cities {
                    res = res.max(
                        travel_score[curr][dest]
                            + solve(
                                &stay_score,
                                &travel_score,
                                &mut dp,
                                day + 1,
                                dest,
                                days,
                                cities,
                            ),
                    );
                }
            }
        }

        res
    }
}

fn solve(
    stay_score: &[Vec<i32>],
    travel_score: &[Vec<i32>],
    dp: &mut [Vec<i32>],
    day: usize,
    curr: usize,
    days: usize,
    cities: usize,
) -> i32 {
    if day >= days {
        return 0;
    }

    if dp[day][curr] != -1 {
        return dp[day][curr];
    }

    let mut res =
        stay_score[day][curr] + solve(stay_score, travel_score, dp, day + 1, curr, days, cities);

    for dest in 0..cities {
        res = res.max(
            travel_score[curr][dest]
                + solve(stay_score, travel_score, dp, day + 1, dest, days, cities),
        );
    }

    dp[day][curr] = res;
    res
}
// @leet end
