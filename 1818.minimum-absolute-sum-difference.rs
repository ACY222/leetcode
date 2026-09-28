// @leet start
impl Solution {
    pub fn min_absolute_sum_diff(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        const DIV: i32 = 1_000_000_007;
        let mut nums1_sorted = nums1.clone();
        nums1_sorted.sort_unstable();

        let mut sum_diff = 0;
        let mut max_decrement = 0;

        for i in 0..nums1.len() {
            let num1 = nums1[i];
            let num2 = nums2[i];

            let orig_diff = (num1 - num2).abs();
            sum_diff += orig_diff;
            if sum_diff > DIV {
                sum_diff -= DIV;
            }

            let closet_num = get_closest_num(&nums1_sorted, num2);
            let curr_diff = (closet_num - num2).abs();
            max_decrement = max_decrement.max((curr_diff - orig_diff).abs());
        }

        let mut res = sum_diff - max_decrement;
        if res < 0 {
            res += DIV;
        }
        res
    }
}

fn get_closest_num(nums: &Vec<i32>, num: i32) -> i32 {
    let idx = nums.partition_point(|&n| n < num);
    // num is greater than all items in nums
    if idx == nums.len() {
        return nums[nums.len() - 1];
    }

    // num is smaller than all items in nums
    if idx == 0 {
        return nums[0];
    }

    let next_num = nums[idx];
    let prev_num = nums[idx - 1];

    if next_num - num < num - prev_num {
        next_num
    } else {
        prev_num
    }
}
// @leet end
