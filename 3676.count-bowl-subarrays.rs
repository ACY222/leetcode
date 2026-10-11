// @leet start
impl Solution {
    pub fn bowl_subarrays(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let left_greater = Self::get_left_greater(&nums);
        let right_greater = Self::get_right_greater(&nums);

        let mut count = 0;
        for i in 1..n - 1 {
            // check the subarray starting from nums[i]
            let l = left_greater[i];
            let mut r = right_greater[i];

            if l != i - 1 || r == usize::MAX {
                continue;
            }

            // [l, i, ..., r],
            //  where l is the first greater element in the left side
            //        r is the first greater element in the right side
            //        and no greater element between (i, r)
            count += 1;

            while nums[l] > nums[r] {
                r = right_greater[r];
                if r != usize::MAX {
                    count += 1;
                } else {
                    break;
                }
            }
        }

        count
    }

    fn get_right_greater(nums: &[i32]) -> Vec<usize> {
        let mut right_greater = vec![usize::MAX; nums.len()];
        let mut st = Vec::new();

        for (i, &num) in nums.iter().enumerate() {
            loop {
                let &top = st.last().unwrap_or(&usize::MAX);
                if top == usize::MAX || nums[top] > num {
                    break;
                }

                st.pop();
                right_greater[top] = i;
            }

            st.push(i);
        }

        right_greater
    }

    fn get_left_greater(nums: &[i32]) -> Vec<usize> {
        let mut left_greater = vec![usize::MAX; nums.len()];
        let mut st = Vec::new();

        for (i, &num) in nums.iter().enumerate().rev() {
            loop {
                let &top = st.last().unwrap_or(&usize::MAX);
                if top == usize::MAX || nums[top] > num {
                    break;
                }

                st.pop();
                left_greater[top] = i;
            }

            st.push(i);
        }

        left_greater
    }
}
// @leet end
