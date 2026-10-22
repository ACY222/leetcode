// @leet start
impl Solution {
    pub fn day_of_year(date: String) -> i32 {
        let mut iter = date.split('-');
        let year = iter.next().unwrap();
        let year: i32 = year.parse().unwrap();

        let month = iter.next().unwrap();
        let month: i32 = month.parse().unwrap();

        let day = iter.next().unwrap();
        let day: i32 = day.parse().unwrap();

        Self::prev_month_days(year, month) + day
    }

    fn prev_month_days(year: i32, month: i32) -> i32 {
        let days = match month {
            1 => 0,
            2 => 31,
            3 => 31 + 28,
            4 => 31 + 28 + 31,
            5 => 31 + 28 + 31 + 30,
            6 => 31 + 28 + 31 + 30 + 31,
            7 => 31 + 28 + 31 + 30 + 31 + 30,
            8 => 31 + 28 + 31 + 30 + 31 + 30 + 31,
            9 => 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
            10 => 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
            11 => 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
            12 => 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
            _ => 0,
        };

        if ((year % 100 == 0 && year % 400 != 0) || year % 4 != 0) || month <= 2 {
            days
        } else {
            days + 1
        }
    }
}
// @leet end
