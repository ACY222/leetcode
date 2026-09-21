// @leet start
impl Solution {
    // operation: + - =
    // variable: x
    // digit
    pub fn solve_equation(equation: String) -> String {
        let (left, right) = equation.split_once('=').unwrap();
        let (x1, const1) = parse(left);
        let (x2, const2) = parse(right);

        let x = x1 - x2;
        let constant = const2 - const1;

        if x == 0 {
            if constant == 0 {
                return "Infinite solutions".to_string();
            } else {
                return "No solution".to_string();
            }
        } else {
            return format!("x={}", constant / x);
        }
    }
}

fn parse(s: &str) -> (i32, i32) {
    let mut x = 0;
    let mut constant = 0;

    let bytes = s.as_bytes();

    let mut idx = 0;

    while idx < bytes.len() {
        let mut sign = 1;

        // + -
        if bytes[idx] == b'+' {
            idx += 1;
        } else if bytes[idx] == b'-' {
            idx += 1;
            sign = -1;
        }

        let mut has_num = false;
        let mut num = 0;

        // digits
        while idx < bytes.len() && bytes[idx].is_ascii_digit() {
            num = num * 10 + (bytes[idx] - b'0') as i32;
            idx += 1;
            has_num = true;
        }

        // no digits any more
        if idx < bytes.len() && bytes[idx] == b'x' {
            // x / -x / +x
            if !has_num {
                num = 1;
            }

            x += num * sign;
            idx += 1;
        } else {
            constant += num * sign;
        }
    }

    (x, constant)
}
// @leet end
