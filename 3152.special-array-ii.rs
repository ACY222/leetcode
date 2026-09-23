// @leet start
impl Solution {
    pub fn is_array_special(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let len = nums.len();
        let mut num_non_special_pairs = vec![0; len];

        for idx in 1..len {
            num_non_special_pairs[idx] = num_non_special_pairs[idx - 1];

            if (nums[idx] - nums[idx - 1]) % 2 == 0 {
                num_non_special_pairs[idx] += 1;
            }
        }

        let mut results = vec![false; queries.len()];

        for (idx, query) in queries.iter().enumerate() {
            let from = query[0] as usize;
            let to = query[1] as usize;

            if num_non_special_pairs[to] - num_non_special_pairs[from] == 0 {
                results[idx] = true;
            }
        }

        results
    }
}
// @leet end
