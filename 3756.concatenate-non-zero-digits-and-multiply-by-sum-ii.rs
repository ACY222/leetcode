// @leet start
impl Solution {
    pub fn sum_and_multiply(s: String, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let (pre_sum, pre_x, non_zero_cnt, pow10) = Self::preprocess(&s);

        const MOD: u64 = 1_000_000_007u64;

        let mut result: Vec<i32> = Vec::with_capacity(queries.len());
        for query in queries {
            let l = query[0] as usize;
            let r = query[1] as usize;

            let sum = if l == 0 {
                pre_sum[r]
            } else {
                (pre_sum[r] - pre_sum[l - 1] + MOD) % MOD
            };

            let cnt_diff = if l == 0 {
                non_zero_cnt[r] as usize
            } else {
                (non_zero_cnt[r] - non_zero_cnt[l - 1]) as usize
            };

            let x = if l == 0 {
                pre_x[r]
            } else {
                let left = pre_x[l - 1] * pow10[cnt_diff] % MOD;
                (pre_x[r] - left + MOD) % MOD
            };

            result.push((sum * x % MOD) as i32);
        }

        result
    }

    fn preprocess(s: &str) -> (Vec<u64>, Vec<u64>, Vec<usize>, Vec<u64>) {
        const MOD: u64 = 1_000_000_007u64;

        let mut pre_sum: Vec<u64> = Vec::with_capacity(s.len());
        let mut pre_x: Vec<u64> = Vec::with_capacity(s.len());
        let mut non_zero_cnt: Vec<usize> = Vec::with_capacity(s.len());

        let mut sum: u64 = 0;
        let mut x: u64 = 0;
        let mut cnt: usize = 0;
        for ch in s.chars() {
            let num = ch.to_digit(10).unwrap() as u64;

            if num > 0 {
                sum = (sum + num) % MOD;
                x = (x * 10 + num) % MOD;
                cnt += 1;
            }

            pre_sum.push(sum);
            pre_x.push(x);
            non_zero_cnt.push(cnt);
        }

        let mut pow10 = vec![1u64; s.len() + 1];
        for i in 0..s.len() {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        (pre_sum, pre_x, non_zero_cnt, pow10)
    }
}
// @leet end
