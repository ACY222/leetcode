// @leet start
impl Solution {
    pub fn trim_mean(arr: Vec<i32>) -> f64 {
        let mut arr = arr;
        arr.sort_unstable();
        let len = arr.len();

        let mut sum = 0;
        for i in len / 20..len - len / 20 {
            sum += arr[i];
        }

        10f64 * sum as f64 / 9f64 / len as f64
    }
}
// @leet end
