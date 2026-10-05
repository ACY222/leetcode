// @leet start
impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        let mut freq = vec![0; nums.len() + 1];
        freq[0] = 1;
        let mut res = 0;

        let mut prefix_sum = 0;
        for num in nums {
            prefix_sum += num;

            if prefix_sum >= goal {
                let target = prefix_sum - goal;

                res += freq[target as usize];
            }

            freq[prefix_sum as usize] += 1;
        }

        res
    }
}
// @leet end
