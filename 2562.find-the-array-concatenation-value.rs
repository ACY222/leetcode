// @leet start
impl Solution {
    pub fn find_the_array_conc_val(nums: Vec<i32>) -> i64 {
        if nums.len() == 1 {
            return nums[0] as i64;
        }
        let mut l = 0;
        let mut r = nums.len() - 1;

        let mut val = 0;
        while l < r {
            val += Self::concatenate(nums[l], nums[r]);
            l += 1;
            r -= 1;
        }

        return if l == r { val + nums[l] as i64 } else { val };
    }

    fn concatenate(num1: i32, num2: i32) -> i64 {
        let orig_num2 = num2 as i64;

        let mut num1 = num1;
        let mut num2 = num2;
        while num2 > 0 {
            num2 /= 10;
            num1 *= 10;
        }

        orig_num2 + num1 as i64
    }
}
// @leet end
