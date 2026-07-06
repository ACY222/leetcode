// @leet start
impl Solution {
    pub fn remove_covered_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_unstable_by(|a, b| {
            if a[0] != b[0] {
                a[0].cmp(&b[0])
            } else {
                b[1].cmp(&a[1])
            }
        });

        let mut ans = intervals.len() as i32;
        let mut max_end = intervals[0][1];

        for i in 1..intervals.len() {
            if max_end >= intervals[i][1] {
                ans -= 1;
            } else {
                max_end = intervals[i][1]
            }
        }

        ans
    }
}
// @leet end
