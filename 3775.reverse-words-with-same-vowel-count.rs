// @leet start
impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut bytes = s.into_bytes();
        let n = bytes.len();

        let is_vowel = |b: u8| -> bool { matches!(b, b'a' | b'e' | b'i' | b'o' | b'u') };

        let mut first_end = 0;
        let mut target_vowel_num = 0;
        while first_end < n && bytes[first_end] != b' ' {
            if is_vowel(bytes[first_end]) {
                target_vowel_num += 1;
            }

            first_end += 1;
        }

        let mut left = first_end + 1;
        while left < n {
            let mut right = left;
            let mut curr_vowel_num = 0;

            while right < n && bytes[right] != b' ' {
                if is_vowel(bytes[right]) {
                    curr_vowel_num += 1;
                }

                right += 1;
            }

            if curr_vowel_num == target_vowel_num {
                bytes[left..right].reverse();
            }

            left = right + 1;
        }

        return String::from_utf8(bytes).unwrap();
    }
}
// @leet end
