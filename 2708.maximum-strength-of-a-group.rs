// @leet start
impl Solution {
    pub fn max_strength(nums: Vec<i32>) -> i64 {
        let mut prod = 1;
        let mut max_neg = i64::MIN;
        let mut num_neg = 0;
        let mut num_pos = 0;
        let mut num_zero = 0;

        for num in nums {
            let num = num as i64;
            if num < 0 {
                num_neg += 1;
                max_neg = max_neg.max(num);
            } else if num == 0 {
                num_zero += 1;
                continue;
            } else {
                num_pos += 1;
            }

            prod *= num;
        }

        if num_pos == 0 && num_neg <= 1 && num_zero > 0 {
            0
        } else if prod > 0 || (prod < 0 && num_neg == 1 && num_pos == 0 && num_zero == 0) {
            prod
        } else {
            prod / max_neg
        }
    }
}
// @leet end
