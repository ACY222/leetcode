// @leet start
impl Solution {
    pub fn count_days(days: i32, meetings: Vec<Vec<i32>>) -> i32 {
        let mut pre_sums = vec![0; (days + 2) as usize];

        for meeting in meetings {
            let start = meeting[0] as usize;
            let end = meeting[1] as usize;

            pre_sums[start] -= 1;
            pre_sums[end + 1] += 1;
        }

        let mut count = -2;
        let mut sum = 0;
        for pre_sum in pre_sums {
            sum += pre_sum;

            if sum >= 0 {
                count += 1;
            }
        }

        count
    }
}
// @leet end
