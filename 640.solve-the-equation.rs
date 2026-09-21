// @leet start
impl Solution {
    // operation: + - =
    // variable: x
    // digit
    pub fn solve_equation(equation: String) -> String {
        let mut coef_x = 0;
        let mut int = 0;

        let mut is_zero = false;
        let mut curr_coef = 0;
        let mut sign = 1;
        let mut before_equal = true;
        for (idx, ch) in equation.chars().enumerate() {
            match ch {
                'x' => {
                    if is_zero {
                        is_zero = false;
                        sign = if before_equal { 1 } else { -1 };
                        continue;
                    } else {
                        coef_x += if curr_coef == 0 { sign } else { curr_coef };
                        curr_coef = 0;
                        sign = if before_equal { 1 } else { -1 };
                    }
                }
                '=' => {
                    int += curr_coef;
                    curr_coef = 0;
                    before_equal = false;
                    sign = -1;
                }
                '+' => {
                    int += curr_coef;
                    curr_coef = 0;
                    sign = if before_equal { 1 } else { -1 };
                }
                '-' => {
                    int += curr_coef;
                    curr_coef = 0;
                    sign = if before_equal { -1 } else { 1 };
                }
                digit => {
                    let digit = digit.to_digit(10).unwrap() as i32;

                    if digit == 0 && curr_coef == 0 {
                        is_zero = true;
                        continue;
                    }
                    curr_coef = curr_coef * 10 + sign * digit;

                    if idx == equation.len() - 1 {
                        int += curr_coef;
                        curr_coef = 0;
                    }
                }
            }
            is_zero = false;
        }

        if coef_x == 0 && int != 0 {
            return "No solution".to_string();
        } else if coef_x == 0 && int == 0 {
            return "Infinite solutions".to_string();
        } else {
            return format!("x={}", -int / coef_x);
        }
    }
}
// @leet end
