// @leet start
impl Solution {
    pub fn check_distances(s: String, distance: Vec<i32>) -> bool {
        let bytes = s.into_bytes();
        let mut distance = distance;

        for dist in 0..bytes.len() {
            let byte = bytes[dist];
            let idx = (byte - b'a') as usize;
            let dist = dist as i32;

            if distance[idx] < 100 {
                distance[idx] += dist + 101;
            } else if distance[idx] != dist + 100 {
                return false;
            }
        }

        true
    }
}
// @leet end
