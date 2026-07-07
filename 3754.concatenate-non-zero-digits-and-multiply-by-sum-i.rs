// @leet start
impl Solution {
    pub fn sum_and_multiply(n: i32) -> i64 {
        let mut n = n;
        let mut x: i64 = 0;
        let mut sum: i64 = 0;
        let mut multiplier: i64 = 1;

        while n > 0 {
            let last = (n % 10) as i64;
            n /= 10;

            if last != 0 {
                x += last * multiplier;
                sum += last;
                multiplier *= 10;
            }
        }

        x * sum
    }
}
// @leet end
