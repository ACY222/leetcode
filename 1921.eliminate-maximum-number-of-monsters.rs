// @leet start
impl Solution {
    pub fn eliminate_maximum(dist: Vec<i32>, speed: Vec<i32>) -> i32 {
        let n = dist.len();
        let mut dist_by_time: Vec<f64> = (0..n)
            .map(|idx| dist[idx] as f64 / speed[idx] as f64)
            .collect();

        dist_by_time.sort_unstable_by(|a, b| a.total_cmp(b));
        let mut num = 0;
        for i in 0..n {
            if dist_by_time[i] > num as f64 {
                num += 1;
            } else {
                break;
            }
        }

        num
    }
}
// @leet end
