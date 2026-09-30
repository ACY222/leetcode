// @leet start
impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let bytes = s.bytes();
        let mut num_l = 0;

        let mut num_split = 0;
        for byte in bytes {
            match byte {
                b'L' => num_l += 1,
                b'R' => num_l -= 1,
                _ => (),
            }

            if num_l == 0 {
                num_split += 1;
            }
        }

        num_split
    }
}
// @leet end
