// @leet start
impl Solution {
    pub fn check_distances(s: String, distance: Vec<i32>) -> bool {
        let bytes = s.into_bytes();
        let mut distance = distance;

        for dist in (0..bytes.len()).rev() {
            let byte = bytes[dist];
            let idx = (byte - b'a') as usize;
            let dist = dist as i32;

            if distance[idx] >= 0 {
                distance[idx] -= dist + 100;
            } else if distance[idx] < 0 {
                distance[idx] += dist + 101;
                if distance[idx] != 0 {
                    return false;
                }
            }
        }

        true
    }
}
// @leet end
