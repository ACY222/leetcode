// @leet start
impl Solution {
    pub fn sum_of_good_integers(n: i32, k: i32) -> i32 {
        let mut sum = 0;
        for num in (n - k).max(0)..=n + k {
            if num & n == 0 {
                sum += num;
            }
        }

        sum
    }
}
// @leet end

