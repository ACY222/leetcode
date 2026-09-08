// @leet start
impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let mut count = 0;

        for num in nums {
            if Self::has_even_digits(num) {
                count += 1;
            }
        }

        count
    }

    fn has_even_digits(num: i32) -> bool {
        let num_digits = num.to_string().len();
        num_digits % 2 == 0
    }
}
// @leet end
