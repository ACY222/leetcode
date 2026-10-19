// @leet start
impl Solution {
    pub fn most_words_found(sentences: Vec<String>) -> i32 {
        let mut count = 0;

        for sentence in sentences {
            count = count.max(sentence.bytes().filter(|&byte| byte == b' ').count() as i32 + 1);
        }

        count
    }
}
// @leet end

