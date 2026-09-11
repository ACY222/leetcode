// @leet start
use std::cmp::Ordering;

impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut open_stack = Vec::new();
        let mut star_stack = Vec::new();

        for (idx, char) in s.chars().enumerate() {
            match char {
                '(' => open_stack.push(idx),
                ')' => {
                    if let Some(_) = open_stack.pop() {
                        continue;
                    } else if let Some(_) = star_stack.pop() {
                        continue;
                    } else {
                        return false;
                    }
                }
                _ => star_stack.push(idx),
            }
        }

        while !open_stack.is_empty() && !star_stack.is_empty() {
            if open_stack.last().unwrap() < star_stack.last().unwrap() {
                open_stack.pop();
                star_stack.pop();
            } else {
                return false;
            }
        }

        open_stack.is_empty()
    }
}
// @leet end
// "((((((()))))))))))(("
// "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())",
// expect: false
//
// open parenthesis: 14
// stars: 14
