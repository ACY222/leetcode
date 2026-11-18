// @leet start
impl Solution {
    pub fn min_changes(s: String) -> i32 {
        let bytes = s.into_bytes();
        let mut diff = 0;
        for pair in bytes.windows(2).step_by(2) {
            if pair[0] != pair[1] {
                diff += 1;
            }
        }

        diff
    }
}
// @leet end
