// @leet start
impl Solution {
    pub fn distribute_candies(n: i32, limit: i32) -> i32 {
        if limit * 3 < n {
            return 0;
        }
        let mut x = n.min(limit);

        let mut count = 0;
        loop {
            let mut y = (n - x).min(limit).min(x);
            let mut z = (n - x - y).min(limit);
            if y < z {
                break;
            }
            while y >= z {
                if x == y && y == z {
                    count += 1;
                } else if x != y && y != z {
                    count += 6;
                } else {
                    count += 3;
                }
                y -= 1;
                z += 1;
            }
            x -= 1;
        }

        count
    }
}
// @leet end
