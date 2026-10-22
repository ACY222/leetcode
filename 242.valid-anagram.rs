// @leet start
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut counts = vec![0; 26];
        for byte in s.bytes() {
            counts[(byte - b'a') as usize] += 1;
        }
        for byte in t.bytes() {
            let idx = (byte - b'a') as usize;
            if counts[idx] == 0 {
                return false;
            }
            counts[idx] -= 1;
        }

        true
    }
}
// @leet end
