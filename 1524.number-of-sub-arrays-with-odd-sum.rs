// @leet start
impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        // odd[i]: the number of subarrays ends at index i with odd sum
        let mut odd = vec![0; arr.len()];
        let mut even = vec![0; arr.len()];
        const MOD: i32 = 1_000_000_007;

        if arr[0] % 2 == 0 {
            even[0] = 1;
        } else {
            odd[0] = 1;
        }

        for i in 1..arr.len() as usize {
            if arr[i] % 2 == 0 {
                even[i] = even[i - 1] + 1;
                odd[i] = odd[i - 1];
            } else {
                even[i] = odd[i - 1];
                odd[i] = even[i - 1] + 1;
            }
        }

        let mut sum = 0;
        for num in odd {
            sum += num;
            sum %= MOD;
        }

        sum
    }
}
// @leet end
