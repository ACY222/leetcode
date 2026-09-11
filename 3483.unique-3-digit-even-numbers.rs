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
            for b in (0..=9) {
                for c in (0..=8).step_by(2) {
                    if freq[a as usize] == 0 || freq[b as usize] == 0 || freq[c as usize] == 0 {
                        continue;
                    }
                    if a == b && b == c {
                        if freq[a as usize] < 3 {
                            continue;
                        }
                    } else if a == b {
                        if freq[a as usize] < 2 {
                            continue;
                        }
                    } else if a == c {
                        if freq[a as usize] < 2 {
                            continue;
                        }
                    } else if b == c {
                        if freq[b as usize] < 2 {
                            continue;
                        }
                    }

                    count += 1;
                }
            }
        }

        count
    }
}
// @leet end
