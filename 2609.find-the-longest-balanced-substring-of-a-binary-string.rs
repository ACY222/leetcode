// @leet start
impl Solution {
    pub fn find_the_longest_balanced_substring(s: String) -> i32 {
        let bytes = s.into_bytes();

        let mut max_len = 0;
        let mut idx = 0;
        while idx < bytes.len() {
            // count 0
            let mut zero_count = 0;
            while idx < bytes.len() && bytes[idx] == b'0' {
                idx += 1;
                zero_count += 1;
            }

            // make_pair for 0, 1
            let mut curr_len = 0;
            while idx < bytes.len() && bytes[idx] == b'1' {
                if zero_count > 0 {
                    zero_count -= 1;
                    curr_len += 2;
                }

                idx += 1;
            }

            max_len = max_len.max(curr_len);
        }

        max_len
    }
}
// @leet end
