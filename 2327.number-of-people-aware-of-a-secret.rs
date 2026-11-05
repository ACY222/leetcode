// @leet start
impl Solution {
    pub fn people_aware_of_secret(n: i32, delay: i32, forget: i32) -> i32 {
        let n = n as usize;
        let delay = delay as usize;
        let forget = forget as usize;
        const MOD: i64 = 1_000_000_007;
        let mut known_people = vec![0i64; n];
        let mut new_people = vec![0i64; n];
        new_people[0] = 1;
        known_people[0] = 1;

        for today in 0..n {
            if today > 0 {
                known_people[today] =
                    (new_people[today] + known_people[today - 1] + known_people[today] + MOD) % MOD;
            }
            // share with new people
            for date in today + delay..n.min(today + forget) {
                new_people[date] = (new_people[today] + new_people[date]) % MOD;
            }
            // old people forget
            if today + forget < n {
                known_people[today + forget] -= new_people[today];
            }
        }

        known_people[n - 1] as i32
    }
}
// @leet end
