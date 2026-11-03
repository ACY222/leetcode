// @leet start
impl Solution {
    pub fn min_speed_on_time(dist: Vec<i32>, hour: f64) -> i32 {
        let mut low = 0;
        let mut high = i32::MAX;

        if dist.len() as f64 - 1.0 + *dist.last().unwrap() as f64 / high as f64 > hour {
            return -1;
        }
        while low < high {
            let speed = (low + high) / 2;
            if can_finish(&dist, hour, speed as f64) {
                high = speed;
            } else {
                low = speed + 1;
            }
        }

        high
    }
}

fn can_finish(dist: &[i32], hour: f64, speed: f64) -> bool {
    let mut total_time: f64 = 0.;
    for &d in dist {
        total_time = total_time.ceil();
        total_time += d as f64 / speed;
    }

    total_time <= hour
}
// @leet end
