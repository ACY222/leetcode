// @leet start
impl Solution {
    pub fn aggregate_time_series(series1: Vec<Vec<i32>>, series2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res = Vec::with_capacity(series1.len() + series2.len());
        let mut i = 0;
        let mut j = 0;
        while i < series1.len() && j < series2.len() {
            if series1[i][0] < series2[j][0] {
                res.push(vec![series1[i][0], series1[i][1] + series2[j][1]]);
                i += 1;
            } else if series1[i][0] == series2[j][0] {
                res.push(vec![series1[i][0], series1[i][1] + series2[j][1]]);
                i += 1;
                j += 1;
            } else {
                res.push(vec![series2[j][0], series1[i][1] + series2[j][1]]);
                j += 1;
            }
        }

        while i < series1.len() {
            res.push(vec![series1[i][0], series1[i][1]]);
            i += 1;
        }

        while j < series2.len() {
            res.push(vec![series2[j][0], series2[j][1]]);
            j += 1;
        }

        res

    }
}
// @leet end
