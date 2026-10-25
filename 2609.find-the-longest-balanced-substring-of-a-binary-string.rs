// @leet start
impl Solution {
    pub fn find_the_longest_balanced_substring(s: String) -> i32 {
        let bytes = s.into_bytes();
        let len = bytes.len();

        let mut max_len = 0;
        let mut idx = 0;
        while idx < len {
            // count 0
            let mut zero_count = 0;
            while idx < len && bytes[idx] == b'0' {
                idx += 1;
                zero_count += 1;
            }

            // count 1
            let mut one_count = 0;
            while idx < len && bytes[idx] == b'1' {
                idx += 1;
                one_count += 1;
            }

            max_len = max_len.max(zero_count.min(one_count) * 2);
        }

        max_len
    }
}
// @leet end
