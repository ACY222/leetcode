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

        open_stack.len() <= star_stack.len()
            && open_stack
                .iter()
                .rev()
                .zip(star_stack.iter().rev())
                .all(|(i, j)| i < j)
    }
}
// @leet end
// "((((((()))))))))))(("
// "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())",
// expect: false
//
// open parenthesis: 14
// stars: 14
