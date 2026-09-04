// @leet start
impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        if n <= 0 {
            return false;
        }

        if n == 1 {
            return true;
        } else {
            if !Self::check_sum_digits(n) {
                return false;
            }
            let mut x = 1;
            let upper_bound = i32::MAX / 3;
            while x < n && x <= upper_bound {
                x *= 3;
            }

            return x == n;
        }
    }

    fn check_sum_digits(n: i32) -> bool {
        let mut sum = 0;
        let mut n = n;
        while n > 0 {
            let last_digit = n % 10;
            sum += last_digit;
            n /= 10;
        }

        return sum % 3 == 0;
    }
}
// @leet end
// │ 2069870691
