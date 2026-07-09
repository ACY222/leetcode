// @leet start
impl Solution {
    fn count_days(days: i32, meetings: Vec<Vec<i32>>) -> i32 {
        let mut events: Vec<(i32, i32)> = Vec::with_capacity(meetings.len() * 2);

        for meeting in meetings {
            let start = meeting[0];
            let end = meeting[1];

            events.push((start, -1));
            events.push((end + 1, 1));
        }

        events.sort_unstable_by_key(|&(idx, _)| idx);

        let mut count = 0;
        let mut cur = 1;
        let mut active = 0;

        for event in events {
            let (idx, offset) = event;

            if idx > cur {
                if active == 0 {
                    count += idx - cur;
                }
                cur = idx;
            }

            // idx == cur
            active += offset;
        }

        if cur <= days {
            count += days + 1 - cur;
        }

        count
    }
}
// @leet end
