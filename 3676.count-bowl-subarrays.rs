// @leet start
impl Solution {
    pub fn bowl_subarrays(nums: Vec<i32>) -> i64 {
        let mut count = 0;
        let mut st = Vec::new();

        for num in nums {
            loop {
                let &top = st.last().unwrap_or(&i32::MAX);
                // if stack is empty or num is less than top
                // just push num into stack
                if top == i32::MAX || top > num {
                    break;
                }

                // if num is greater than top
                st.pop();
                count += !st.is_empty() as i64;
            }

            st.push(num);
        }

        count
    }
}
// @leet end
