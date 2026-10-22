// @leet start
impl Solution {
    pub fn day_of_year(date: String) -> i32 {
        let year: i32 = date[0..4].parse().unwrap();
        let month: usize = date[5..7].parse().unwrap();
        let day: i32 = date[8..10].parse().unwrap();

        let mut days = vec![0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334];

        let is_leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        if is_leap_year {
            for month in 2..days.len() {
                days[month] += 1;
            }
        }

        day + days[month - 1]
    }
}
// @leet end
