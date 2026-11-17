// @leet start
impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut bytes = s.into_bytes();
        let mut k = 0;

        for i in 0..bytes.len() {
            if bytes[i].is_ascii_digit() {
                k -= 1;
            } else {
                bytes[k] = bytes[i];
                k += 1;
            }
        }

        bytes.truncate(k);
        String::from_utf8(bytes).unwrap()
    }
}
// @leet end
