// @leet start
impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        if n > 2 {
            let mut n1 = 0;
            let mut n2 = 1;
            let mut n3 = 1;

            let mut res = 2;

            for _ in 3..=n {
                res = n1 + n2 + n3;
                n1 = n2;
                n2 = n3;
                n3 = res;
            }
            res
        } else if n == 0 {
            0
        } else {
            1
        }
    }
}
// @leet end

