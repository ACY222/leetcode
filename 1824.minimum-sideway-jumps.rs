// @leet start
impl Solution {
    pub fn min_side_jumps(obstacles: Vec<i32>) -> i32 {
        let mut jumps = vec![1, 0, 1];
        let mut min_jump = 0;
        for obs in obstacles {
            if obs == 0 {
                for lane in 0..3 as usize {
                    jumps[lane] = jumps[lane].min(min_jump + 1);
                }

                continue;
            }

            let obs = obs as usize - 1;
            let lane1 = (obs + 1) % 3;
            let lane2 = (obs + 2) % 3;

            // in case the addition below overflow
            jumps[obs] = i32::MAX - 1;
            jumps[lane1] = jumps[lane1].min(jumps[lane2] + 1);
            jumps[lane2] = jumps[lane2].min(jumps[lane1] + 1);

            min_jump = i32::min(jumps[lane1], jumps[lane2]);
        }

        min_jump
    }
}
// @leet end
