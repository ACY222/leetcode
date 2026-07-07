// @leet start
impl Solution {
    pub fn sum_and_multiply(mut n: i32) -> i64 {
        let mut x = 0i64;
        let mut sum = 0i64;
        let mut count = 0u32;

        while n > 0 {
            let last = (n % 10) as i64;
            n /= 10;

            if last != 0 {
                x += last * 10i64.pow(count);
                sum += last;
                count += 1;
            }
        }

        x * sum
    }
}
// @leet end
