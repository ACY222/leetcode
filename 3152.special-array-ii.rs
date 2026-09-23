// @leet start
impl Solution {
    pub fn is_array_special(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let len = nums.len();
        let mut special_arrays = Vec::new();
        let mut idx = 0;

        while idx < len - 1 {
            // is special pair
            if (nums[idx] - nums[idx + 1]) % 2 != 0 {
                let from = idx as i32;

                while idx < len - 1 && (nums[idx] - nums[idx + 1]) % 2 != 0 {
                    idx += 1;
                }

                let to = idx as i32;
                special_arrays.push((from, to));
            }

            idx += 1;
        }

        let mut results = vec![false; queries.len()];
        for (i, query) in queries.iter().enumerate() {
            let from = query[0];
            let to = query[1];

            if from == to {
                results[i] = true;
                continue;
            }

            let idx = special_arrays.partition_point(|&(start, _)| start <= from);
            if idx > 0 && special_arrays[idx - 1].1 >= to {
                results[i] = true;
            }
        }

        results
    }
}
// @leet end
