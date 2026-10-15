// @leet start
impl Solution {
    pub fn next_greater_element(n: i32) -> i32 {
        let mut digits = Vec::new();
        let mut n = n;
        while n > 0 {
            let last_digit = n % 10;
            digits.push(last_digit);
            n /= 10;
        }

        for j in 1..digits.len() {
            if digits[..=j].is_sorted() {
                continue;
            }

            for i in 0..j {
                // find the first element greater than digits[j]
                if digits[i] <= digits[j] {
                    continue;
                }
                digits.swap(i, j);
                digits[..j].sort_unstable_by(|a, b| b.cmp(a));
                break;
            }

            let mut res = 0;
            let mut multiply = 1;
            for digit in digits {
                if digit > (i32::MAX - res) / multiply {
                    return -1;
                }
                res += digit * multiply;
                multiply *= 10;
            }

            return res;
        }

        -1
    }
}
// @leet end
