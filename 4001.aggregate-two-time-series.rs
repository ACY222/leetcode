// @leet start
impl Solution {
    pub fn aggregate_time_series(series1: Vec<Vec<i32>>, series2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (series1.len(), series2.len());
        let mut res = Vec::with_capacity(m + n);
        let (mut i, mut j) = (0, 0);

        while i < m || j < n {
            if j == n || (i < m && series1[i][0] < series2[j][0]) {
                res.push(vec![series1[i][0], series1[i][1] +
                    if j < n { series2[j][1] } else { 0 } ]);
                i += 1;
            } else if i == m || (j < n && series1[i][0] > series2[j][0]) {
                res.push(vec![series2[j][0], series2[j][1] +
                    if i < m { series1[i][1] } else { 0 } ]);
                j += 1;
            } else {
                res.push(vec![series1[i][0], series1[i][1] + series2[j][1]]);
                i += 1;
                j += 1;
            }
        }
        res
    }
}
// @leet end
