// @leet start
use std::collections::BinaryHeap;
impl Solution {
    pub fn number_of_weeks(milestones: Vec<i32>) -> i64 {
        let sum: i64 = milestones.iter().map(|&x| x as i64).sum();
        let mut max_heap = BinaryHeap::from(milestones);

        if max_heap.len() >= 3 {
            let max = *max_heap.peek().unwrap() as i64;
            // cannot work all projects
            if max > sum - max + 1 {
                return (sum - max) * 2 + 1;
            } else {
                return sum;
            }
        } else if max_heap.len() == 2 {
            let first = max_heap.pop().unwrap();
            let second = max_heap.pop().unwrap();

            return 2 * second as i64 + if first == second { 0 } else { 1 };
        } else {
            return 1;
        }
    }
}
// @leet end
