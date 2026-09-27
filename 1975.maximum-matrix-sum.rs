// @leet start
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut min = i32::MAX;
        let mut sum = 0;
        let mut neg_count = 0;

        for row in matrix {
            for num in row {
                let num_abs = if num < 0 {
                    neg_count += 1;
                    -num
                } else {
                    num
                };

                min = num_abs.min(min);
                sum += num_abs as i64;
            }
        }

        if neg_count % 2 == 0 {
            return sum;
        } else {
            return sum - min as i64 * 2;
        }
    }
}
// @leet end
