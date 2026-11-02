// @leet start
impl Solution {
    pub fn first_matching_index(s: String) -> i32 {
        let bytes = s.into_bytes();
        let n = bytes.len();
        for i in 0..=n / 2 {
            if bytes[i] == bytes[n - i - 1] {
                return i as i32;
            }
        }

        -1
    }
}
// @leet end
