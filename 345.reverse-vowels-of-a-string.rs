// @leet start
impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let mut bytes = s.into_bytes();

        let mut left = 0;
        let mut right = bytes.len() - 1;
        while left < right {
            while left < right && !is_vowel(bytes[left]) {
                left += 1;
            }
            while right > left && !is_vowel(bytes[right]) {
                right -= 1;
            }

            if left < right {
                bytes.swap(left, right);
                left += 1;
                right -= 1;
            }
        }

        String::from_utf8(bytes).unwrap()
    }
}
fn is_vowel(char: u8) -> bool {
    char == b'a'
        || char == b'A'
        || char == b'e'
        || char == b'E'
        || char == b'i'
        || char == b'I'
        || char == b'o'
        || char == b'O'
        || char == b'u'
        || char == b'U'
}
// @leet end
