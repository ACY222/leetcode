// @leet start
impl Solution {
    pub fn min_flips(s: String) -> i32 {
        let one_count = s.matches('1').count();
        let zero_count = s.len() - one_count;

        let bytes = s.into_bytes();

        // all 0 or at most one 1
        if zero_count == 0 || one_count < 2 {
            return 0;
        }

        return usize::min(
            one_count
                - if bytes[0] == b'1' && bytes[bytes.len() - 1] == b'1' {
                    2
                } else {
                    1
                },
            zero_count,
        ) as i32;
    }
}
// @leet end
