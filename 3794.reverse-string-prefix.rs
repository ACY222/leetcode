// @leet start
impl Solution {
    pub fn reverse_prefix(s: String, k: i32) -> String {
        let mut slice = s.into_bytes();
        slice[..k as usize].reverse();
        String::from_utf8(slice).unwrap()
    }
}
// @leet end
