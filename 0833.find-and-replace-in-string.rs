// @leet start
impl Solution {
    pub fn find_replace_string(s: String, indices: Vec<i32>, sources: Vec<String>, targets: Vec<String>) -> String {
        let k = indices.len();
        let mut operations: Vec<(usize, &str, &str)> = indices
            .iter()
            .zip(sources.iter())
            .zip(targets.iter())
            .map(|((&idx, src), tgt)| (idx as usize, src.as_str(), tgt.as_str()))
            .collect();

        operations.sort_unstable_by_key(|&(idx, _, _)| idx);

        let mut result = String::with_capacity(k);
        let mut pos: usize = 0;

        for (idx, src, tgt) in operations {
            if pos > idx {
                continue;
            }

            result.push_str(&s[pos..idx]);
            pos = idx;

            if s[idx..].starts_with(src) {
                result.push_str(tgt);
                pos += src.len();
            }
        }

        result.push_str(&s[pos..]);

        result
    }
}
// @leet end
