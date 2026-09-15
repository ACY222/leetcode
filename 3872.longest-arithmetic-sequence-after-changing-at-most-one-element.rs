// @leet start
impl Solution {
    pub fn longest_arithmetic(nums: Vec<i32>) -> i32 {
        // length of longest arithmetic array ending with i
        let n = nums.len();
        let mut left = vec![2; n];
        // length of longest arithmetic array starting with i
        let mut right = vec![2; n];

        for i in 2..n {
            if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] {
                left[i] = 1 + left[i - 1]
            }
        }

        for i in (0..=n - 3).rev() {
            if nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1] {
                right[i] = 1 + right[i + 1];
            }
        }

        let mut max_len = 2;
        for i in 1..n - 1 {
            // extend right or left
            max_len = max_len.max(right[i] + 1);
            max_len = max_len.max(left[i] + 1);

            // combine left and right
            if (nums[i + 1] - nums[i - 1]) % 2 == 0 {
                let diff = (nums[i + 1] - nums[i - 1]) / 2;
                let left_len = if i >= 2 && nums[i - 1] - nums[i - 2] == diff {
                    left[i - 1]
                } else {
                    1
                };
                let right_len = if i + 2 < n && nums[i + 2] - nums[i + 1] == diff {
                    right[i + 1]
                } else {
                    1
                };

                max_len = max_len.max(left_len + right_len + 1);
            }
        }

        max_len
    }
}
// @leet end
