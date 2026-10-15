// @leet start
use std::collections::HashSet;

impl Solution {
    pub fn longest_word(words: Vec<String>) -> String {
        let mut words = words;
        words.sort_unstable();

        let mut prefix = HashSet::new();
        let mut longest = String::new();

        for word in words {
            if word.len() == 1 || prefix.contains(&word[0..word.len() - 1]) {
                if word.len() > longest.len() {
                    longest = word.clone();
                }

                prefix.insert(word);
            }
        }

        longest
    }
}
// @leet end
