// @leet start
impl Solution {
    pub fn day_of_year(date: String) -> i32 {
        let year: i32 = date[0..4].parse().unwrap();
        let month: i32 = date[5..7].parse().unwrap();
        let day: i32 = date[8..10].parse().unwrap();

        let days = vec![0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334];

        day + days[month as usize - 1]
            + if ((year % 100 == 0 && year % 400 != 0) || year % 4 != 0) || month <= 2 {
                0
            } else {
                1
            }
    }
}
// @leet end
