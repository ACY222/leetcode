// @leet start
use std::collections::HashMap;
impl Solution {
    pub fn minimum_index(nums: Vec<i32>) -> i32 {
        let left_dominants = find_left_dominants(&nums);
        let right_dominants = find_right_dominants(&nums);

        let mut idx = 0;
        while idx < nums.len() - 1 {
            if left_dominants[idx] != 0 && left_dominants[idx] == right_dominants[idx + 1] {
                return idx as i32;
            }

            idx += 1;
        }

        -1
    }
}

fn find_left_dominants(nums: &[i32]) -> Vec<i32> {
    let mut num_freq: HashMap<i32, usize> = HashMap::new();
    let mut dominants = vec![0i32; nums.len()];

    for (idx, &num) in nums.iter().enumerate() {
        num_freq
            .entry(num)
            .and_modify(|freq| *freq += 1)
            .or_insert(1);

        if idx > 0 && dominants[idx - 1] != 0 && num_freq[&dominants[idx - 1]] * 2 > idx + 1 {
            dominants[idx] = dominants[idx - 1];
        } else if num_freq[&num] * 2 > idx + 1 {
            dominants[idx] = num;
        }
    }

    dominants
}

fn find_right_dominants(nums: &[i32]) -> Vec<i32> {
    let mut num_freq: HashMap<i32, usize> = HashMap::new();
    let mut dominants = vec![0i32; nums.len()];

    for (idx, &num) in nums.iter().rev().enumerate() {
        num_freq
            .entry(num)
            .and_modify(|freq| *freq += 1)
            .or_insert(1);

        if idx > 0 && dominants[idx - 1] != 0 && num_freq[&dominants[idx - 1]] * 2 > idx + 1 {
            dominants[idx] = dominants[idx - 1];
        } else if num_freq[&num] * 2 > idx + 1 {
            dominants[idx] = num;
        }
    }

    dominants.reverse();
    dominants
}
// @leet end
