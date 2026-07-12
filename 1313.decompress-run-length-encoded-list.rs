// @leet start
impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        let total_size = nums.chunks_exact(2).map(|c| c[0] as usize).sum();
        let mut result = Vec::with_capacity(total_size);

        for c in nums.chunks_exact(2) {
            result.extend(std::iter::repeat(c[1]).take(c[0] as usize));
        }

        result
    }
}
// @leet end
