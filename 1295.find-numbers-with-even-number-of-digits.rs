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
        if num < 10 {
            false
        } else if num < 100 {
            true
        } else if num < 1_000 {
            false
        } else if num < 10_000 {
            true
        } else if num < 100_000 {
            false
        } else {
            true
        }
    }
}
// @leet end
