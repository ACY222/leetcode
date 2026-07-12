// @leet start
impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::with_capacity(nums.len());

        for (freq, val) in nums.chunks_exact(2).map(|c| (c[0], c[1])) {
            for _ in 0..freq {
                result.push(val);
            }
        }

        result
    }
}
// @leet end
