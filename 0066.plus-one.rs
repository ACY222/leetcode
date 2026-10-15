// @leet start
impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;

        let mut has_carry = true;
        for digit in digits.iter_mut().rev() {
            if !has_carry {
                break;
            }

            *digit += 1;

            if *digit == 10 {
                *digit = 0;
            } else {
                has_carry = false;
            }
        }

        if has_carry {
            digits.insert(0, 1);
        }

        digits
    }
}
// @leet end
