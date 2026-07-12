// @leet start
impl Solution {
    pub fn satisfies_conditions(grid: Vec<Vec<i32>>) -> bool {
        let first_row = &grid[0];

        for i in 0..first_row.len() - 1 {
            if first_row[i] == first_row[i + 1] {
                return false;
            }
        }

        for row in &grid[1..] {
            if row != first_row {
                return false;
            }
        }

        true
    }
}
// @leet end
