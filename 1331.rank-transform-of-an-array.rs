// @leet start
impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        if arr.len() == 0 {
            return arr;
        }
        // [40, 10, 20, 30]
        let mut sorted_with_idx: Vec<(i32, usize)> = arr
            .iter()
            .enumerate()
            .map(|(idx, &val)| (val, idx))
            .collect();

        // [(40, 0), (10, 1), (20, 2), (30, 3)]
        sorted_with_idx.sort_unstable_by_key(|&(val, _)| val);

        // [(10, 1), (20, 2), (30, 3), (40, 0)]
        let mut rank = 1;
        let mut prev = sorted_with_idx[0].0;

        let mut idx_and_rank: Vec<(usize, i32)> = sorted_with_idx
            .iter()
            .map(|&(val, idx)| {
                if val > prev {
                    rank += 1;
                    prev = val;
                }
                (idx, rank)
            })
            .collect();

        // (1, 1), (2, 2), (3, 3), (0, 4)
        idx_and_rank.sort_unstable_by_key(|&(idx, _)| idx);
        let result: Vec<i32> = idx_and_rank.iter().map(|&(_, rank)| rank).collect();

        // (4, 1, 2, 3)
        result
    }
}
// @leet end
