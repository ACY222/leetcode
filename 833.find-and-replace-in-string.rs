// @leet start
use std::iter::FromIterator;

struct Find {
    index: usize,
    i: usize,
    need_replace: bool,
}

impl Solution {
    pub fn find_replace_string(
        s: String,
        indices: Vec<i32>,
        sources: Vec<String>,
        targets: Vec<String>) -> String {

        let k = indices.len();
        let mut s = s;
        let mut finds = Vec::from_iter((0..k).map(|i| Find {
            index: indices[i] as usize,
            i: i as usize,
            need_replace: false
        }));

        for i in 0..k {
            finds[i].need_replace = Self::is_substring_match(&s, indices[i] as usize, &sources[i]);
        }

        finds.sort_by(|find1, find2| find2.index.cmp(&find1.index));

        for i in 0..k {
            if finds[i].need_replace {
                Self::replace_substring(&mut s, indices[finds[i].i] as usize, sources[finds[i].i].len(), &targets[finds[i].i]);
            }
        }

        s
    }

    fn is_substring_match(s: &str, index: usize, pattern: &str) -> bool {
        if index + pattern.len() > s.len() {
            return false;
        }

        &s[index..index + pattern.len()] == pattern
    }

    fn replace_substring(s: &mut String, index: usize, len: usize, target: &str) {
        s.replace_range(index..index + len, target);
    }
}
// @leet end
