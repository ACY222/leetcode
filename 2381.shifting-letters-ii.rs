// @leet start
impl Solution {
    pub fn shifting_letters(s: String, shifts: Vec<Vec<i32>>) -> String {
        let mut diff = vec![0; s.len() + 1];

        for shift in shifts {
            let start = shift[0] as usize;
            let end = shift[1] as usize;
            let dir = if shift[2] == 1 { 1 } else { -1 };

            diff[start] += dir;
            diff[end + 1] -= dir;
        }

        let mut curr_shift = 0;
        let base = b'a' as i32;
        let mut bytes = s.into_bytes();
        for idx in 0..bytes.len() {
            curr_shift += diff[idx];

            let curr_char = bytes[idx] as i32;
            let shifted = (curr_char - base + curr_shift).rem_euclid(26) + base;
            bytes[idx] = shifted as u8;
        }

        String::from_utf8(bytes).unwrap()
    }
}
// @leet end
