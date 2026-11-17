// @leet start
impl Solution {
    pub fn clear_digits(s: String) -> String {
        let bytes = s.into_bytes();
        let mut res: Vec<u8> = Vec::with_capacity(bytes.len());
        for byte in bytes {
            if byte.is_ascii_digit() && !res.is_empty() && !res.last().unwrap().is_ascii_digit() {
                    res.pop();
            } else {
                res.push(byte);
            }
        }


        String::from_utf8(res).unwrap()

    }
}
// @leet end
