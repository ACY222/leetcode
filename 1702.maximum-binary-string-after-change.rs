// @leet start
impl Solution {
    // There is at most one `0` left
    // 000..00 -> 111..10
    // 011..10 -> 101..11
    // each '0' can move the first '1' one index forward
    pub fn maximum_binary_string(binary: String) -> String {
        // convert first consecutive '000' to '110'
        let bytes = binary.as_bytes();

        let mut has_zero = false;
        let mut i = 0;
        while i < bytes.len() {
            if bytes[i] == b'0' {
                has_zero = true;
                i += 1;
                while i < bytes.len() && bytes[i] == b'0' {
                    i += 1;
                }
                break;
            }
            i += 1;
        }

        if !has_zero {
            return binary;
        }

        // index of first '0' in the string
        let mut idx = i - 1;

        // plus the number of '0' in the string (except the first one)
        while i < binary.len() {
            if bytes[i] == b'0' {
                idx += 1;
            }
            i += 1;
        }
        let mut result = "1".repeat(bytes.len());
        result.replace_range(idx..=idx, "0");

        result
    }
}
// @leet end
