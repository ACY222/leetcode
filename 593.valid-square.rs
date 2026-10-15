// @leet start
impl Solution {
    pub fn valid_square(p1: Vec<i32>, p2: Vec<i32>, p3: Vec<i32>, p4: Vec<i32>) -> bool {
        if p1 == p2 {
            return false;
        }
        let p12_sq = i32::pow(p1[0] - p2[0], 2) + i32::pow(p1[1] - p2[1], 2);
        let p23_sq = i32::pow(p2[0] - p3[0], 2) + i32::pow(p2[1] - p3[1], 2);
        let p13_sq = i32::pow(p1[0] - p3[0], 2) + i32::pow(p1[1] - p3[1], 2);

        if p12_sq == p23_sq && 2 * p12_sq == p13_sq {
            return get_last_point(&p1, &p2, &p3) == p4;
        } else if p12_sq == p13_sq && 2 * p12_sq == p23_sq {
            return get_last_point(&p2, &p1, &p3) == p4;
        } else if p13_sq == p23_sq && 2 * p13_sq == p12_sq {
            return get_last_point(&p1, &p3, &p2) == p4;
        }
        false
    }
}

fn get_last_point(p1: &[i32], p2: &[i32], p3: &[i32]) -> Vec<i32> {
    vec![p1[0] + (p3[0] - p2[0]), p1[1] + (p3[1] - p2[1])]
}
// @leet end
