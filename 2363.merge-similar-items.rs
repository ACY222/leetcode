// @leet start
impl Solution {
    pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut weights = vec![0; 1001];

        for item in items1 {
            weights[item[0] as usize] += item[1];
        }

        for item in items2 {
            weights[item[0] as usize] += item[1];
        }

        let mut res = Vec::with_capacity(500);
        for (value, &weight) in weights.iter().enumerate() {
            if weight != 0 {
                res.push(vec![value as i32, weight]);
            }
        }

        res
    }
}
// @leet end
