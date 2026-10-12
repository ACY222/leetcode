// @leet start
impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        if n > 2 {
            let mut n1 = 0;
            let mut n2 = 1;
            let mut n3 = 1;

            for _ in 3..=n {
                (n1, n2, n3) = (n2, n3, n1 + n2 + n3);
            }
            n3
        } else if n == 0 {
            0
        } else {
            1
        }
    }
}
// @leet end
