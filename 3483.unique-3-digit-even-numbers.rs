// @leet start
impl Solution {
    // even numbers
    pub fn total_numbers(digits: Vec<i32>) -> i32 {
        let mut freq = vec![0; 10];
        for digit in digits {
            freq[digit as usize] += 1;
        }

        let mut count = 0;
        for a in (1..=9) {
            if freq[a as usize] == 0 {
                continue;
            }

            freq[a as usize] -= 1;

            for b in (0..=9) {
                if freq[b as usize] == 0 {
                    continue;
                }

                freq[b as usize] -= 1;

                for c in (0..=8).step_by(2) {
                    if freq[c as usize] == 0 {
                        continue;
                    }
                    count += 1;
                }

                freq[b as usize] += 1;
            }

            freq[a as usize] += 1;
        }

        count
    }
}
// @leet end
