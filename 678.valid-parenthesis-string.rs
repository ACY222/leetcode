// @leet start
use std::cmp::Ordering;

impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let bytes = s.as_bytes();

        let mut num_open = 0;
        let mut num_close = 0;
        let mut num_star = 0;

        for &byte in bytes {
            match byte {
                b'(' => {
                    num_open += 1;
                }
                b'*' => {
                    num_star += 1;
                }
                b')' => {
                    num_close += 1;
                }
                _ => {}
            }
        }

        let (mut new_open, mut need_skip) = match num_open.cmp(&num_close) {
            Ordering::Less => {
                let diff = num_close - num_open;
                ((num_star + diff) / 2, (num_star - diff) % 2 == 1)
            }
            Ordering::Equal => (num_star / 2, num_star % 2 == 1),
            Ordering::Greater => {
                let diff = num_open - num_close;
                ((num_star - diff) / 2, (num_star - diff) % 2 == 1)
            }
        };

        let mut num_open = 0;
        for &byte in bytes {
            if byte == b'(' {
                num_open += 1;
            } else if byte == b')' {
                num_open -= 1;
            } else {
                // *
                if new_open > 0 {
                    num_open += 1;
                    new_open -= 1;
                } else if need_skip {
                    need_skip = false;
                } else {
                    num_open -= 1;
                }
            }

            if num_open < 0 {
                return false;
            }
        }

        if num_open != 0 {
            return false;
        }

        true
    }
}
// @leet end
// "((((((()))))))))))(("
// "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())",
// expect: false
//
// open parenthesis: 14
// stars: 14
