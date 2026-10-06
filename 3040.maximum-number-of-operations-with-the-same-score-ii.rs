// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn max_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();

        let val1 = nums[0] + nums[1];
        let val2 = nums[0] + nums[n - 1];
        let val3 = nums[n - 2] + nums[n - 1];

        let mut op_counts = HashMap::new();
        let count1 = seek_max_operations(&nums, val1, 2, n - 1, &mut op_counts);
        let count2 = seek_max_operations(&nums, val2, 1, n - 2, &mut op_counts);
        let count3 = if n > 2 {
            seek_max_operations(&nums, val3, 0, n - 3, &mut op_counts)
        } else {
            0
        };

        1 + count1.max(count2).max(count3)
    }
}

fn seek_max_operations(
    nums: &[i32],
    val: i32,
    left: usize,
    right: usize,
    op_counts: &mut HashMap<(usize, usize), i32>,
) -> i32 {
    if left >= right {
        return 0;
    }

    if let Some(&count) = op_counts.get(&(left, right)) {
        return count;
    }

    let mut count = 0;
    if nums[left] + nums[left + 1] == val {
        count = count.max(1 + seek_max_operations(&nums, val, left + 2, right, op_counts));
    }
    if nums[left] + nums[right] == val {
        count = count.max(1 + seek_max_operations(&nums, val, left + 1, right - 1, op_counts));
    }
    if left + 1 != right && nums[right - 1] + nums[right] == val {
        count = count.max(1 + seek_max_operations(&nums, val, left, right - 2, op_counts));
    }

    op_counts.insert((left, right), count);

    count
}
// @leet end
