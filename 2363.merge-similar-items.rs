// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res = HashMap::with_capacity(items1.len() + items2.len());
        for item in items1 {
            let value = item[0];
            let weight = item[1];

            *res.entry(value).or_insert(0) += weight;
        }

        for item in items2 {
            let value = item[0];
            let weight = item[1];

            *res.entry(value).or_insert(0) += weight;
        }

        let mut res: Vec<Vec<i32>> = res.into_iter().map(|(k, v)| vec![k, v]).collect();
        res.sort_unstable();

        res
    }
}
// @leet end
