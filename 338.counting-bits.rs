// @leet start
impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut results = vec![0; n as usize + 1];
        for num in 1..=n as usize {
            if num % 2 == 1 {
                // base is odd
                results[num] = results[num / 2] + 1;
            } else {
                // base is even
                results[num] = results[num / 2];
            }
        }

        results
    }
}
// @leet end

