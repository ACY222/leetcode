// @leet start
impl Solution {
    pub fn get_least_frequent_digit(n: i32) -> i32 {
        let mut freqs: [u8; 10] = [0; 10];
        let mut n = n;

        while n > 0 {
            let last = n % 10;
            n /= 10;

            freqs[last as usize] += 1;
        }

        let mut min_freq = u8::MAX;
        let mut least_digit = -1;

        for (digit, &freq) in freqs.iter().enumerate() {
            if freq > 0 && freq < min_freq {
                least_digit = digit as i32;
                min_freq = freq;
            }
        }

        least_digit
    }
}
// @leet end
