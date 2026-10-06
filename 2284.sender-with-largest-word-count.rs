// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn largest_word_count(messages: Vec<String>, senders: Vec<String>) -> String {
        let mut word_counts = HashMap::new();

        for idx in 0..messages.len() {
            let sender = &senders[idx];
            let message = &messages[idx];

            let count = message.split_whitespace().count();
            let word_count = word_counts.entry(sender.clone()).or_insert(0);
            *word_count += count;
        }

        word_counts
            .iter()
            .max_by(|a, b| a.1.cmp(b.1).then_with(|| a.0.cmp(b.0)))
            .map(|(sender, _)| sender.clone())
            .unwrap()
    }
}
// @leet end
