// @leet start
use std::cmp::min;
impl Solution {
    pub fn count_commas(n: i64) -> i64 {
        let mut count = 0i64;
        if n >= 1e3 as i64 {
            count += min(n + 1, 1e6 as i64) - 1e3 as i64;

            if n >= 1e6 as i64 {
                count += 2 * (min(n + 1, 1e9 as i64) - 1e6 as i64);

                if n >= 1e9 as i64 {
                    count += 3 * (min(n + 1, 1e12 as i64) - 1e9 as i64);

                    if n >= 1e12 as i64 {
                        count += 4 * (min(n + 1, 1e15 as i64) - 1e12 as i64);

                        if n == 1e15 as i64 {
                            count += 5;
                        }
                    }
                }
            }
        }

        count
    }
}
// @leet end
