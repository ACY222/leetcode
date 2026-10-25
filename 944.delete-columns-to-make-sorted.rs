// @leet start
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let vec_bytes: Vec<Vec<u8>> = strs.into_iter().map(String::into_bytes).collect();
        let rows = vec_bytes.len();
        let cols = vec_bytes[0].len();
        let mut count = 0;
        for col in 0..cols {
            for row in 0..rows - 1 {
                if vec_bytes[row][col] > vec_bytes[row + 1][col] {
                    count += 1;
                    break;
                }
            }
        }
        count
    }
}
// @leet end

