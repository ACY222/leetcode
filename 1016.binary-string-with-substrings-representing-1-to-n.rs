// @leet start
impl Solution {
    pub fn query_string(s: String, n: i32) -> bool {
        let mut mul = 1;
        while mul < n / 2 {
            mul *= 2;
        }
        let lower = mul;
        let upper = n;

        for i in lower..=upper {
            let binary = format!("{i:b}");
            if s.find(&binary) == None {
                return false;
            }
        }

        true
    }
}
// @leet end

// 7: 1 10 11 100 101 110 111
// 1
// 10 11
// 100 110 111 101
