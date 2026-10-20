// @leet start
use std::collections::BinaryHeap;
impl Solution {
    pub fn number_of_weeks(milestones: Vec<i32>) -> i64 {
        let mut max_heap = BinaryHeap::with_capacity(milestones.len());
        for elem in milestones {
            max_heap.push(elem);
        }

        let mut val_to_push = -1;
        let mut need_to_push = false;

        let mut num = 0;

        while !max_heap.is_empty() {
            let mut max = max_heap.pop().unwrap();
            num += 1;
            max -= 1;

            if need_to_push {
                max_heap.push(val_to_push);
                need_to_push = false;
            } else if max_heap.is_empty() {
                break;
            }

            if max > *max_heap.peek().unwrap() {
                need_to_push = true;
                val_to_push = max;
            } else if max > 0 {
                max_heap.push(max);
            }
        }

        num
    }
}
// @leet end
