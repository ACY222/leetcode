// @leet start
impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();
        let mut max_vals = vec![0; len];
        let mut min_vals = vec![0; len];

        let mut max_val = i32::MIN;
        let mut min_val = i32::MAX;

        for (i, &num) in nums.iter().enumerate() {
            if num > max_val {
                max_val = num;
            }
            max_vals[i] = max_val;
        }

        for (i, &num) in nums.iter().enumerate().rev() {
            if num < min_val {
                min_val = num;
            }
            min_vals[i] = min_val;
        }

        for i in 0..len {
            if max_vals[i] - min_vals[i] <= k {
                return i as i32;
            }
        }
        // otherwise return -1
        -1
    }
}
// @leet end
