// @leet start
impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        // odd[i]: the number of subarrays ends at index i with odd sum
        let mut odd = 0;
        let mut even = 0;
        const MOD: i32 = 1_000_000_007;

        let mut sum = 0;
        for num in arr {
            if num % 2 == 0 {
                even += 1;
            } else {
                std::mem::swap(&mut even, &mut odd);
                odd += 1;
            }

            sum = (sum + odd) % MOD;
        }

        sum
    }
}
// @leet end
