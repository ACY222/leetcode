// @leet start
impl Solution {
    pub fn reverse_prefix(s: String, k: i32) -> String {
        let mut slice = s.into_bytes();
        // 5: 0, 1
        // 4: 0, 1
        let k = k as usize;
        for idx in 0..k / 2 {
            slice.swap(idx, k - 1 - idx);
        }

        String::from_utf8(slice).unwrap()
    }
}
// @leet end
