// @leet start
impl Solution {
    pub fn min_flips(s: String) -> i32 {
        let bytes = s.into_bytes();

        let mut one_count = 0;
        for &b in &bytes {
            if b == b'1' {
                one_count += 1;
            }
        }

        let zero_count = bytes.len() - one_count;

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
