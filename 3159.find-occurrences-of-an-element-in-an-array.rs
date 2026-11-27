// @leet start
impl Solution {
    pub fn occurrences_of_element(nums: Vec<i32>, queries: Vec<i32>, x: i32) -> Vec<i32> {
        let mut indices = Vec::with_capacity(queries.len());
        for (idx, &num) in nums.iter().enumerate() {
            if num == x {
                indices.push(idx as i32);
            }
        }

        let mut answers = Vec::with_capacity(queries.len());
        let max_idx = indices.len() as i32;

        for query in queries {
            if query > max_idx {
                answers.push(-1);
            } else {
                answers.push(indices[query as usize - 1]);
            }
        }

        answers
    }
}
// @leet end
