// @leet start
impl Solution {
    pub fn is_winner(player1: Vec<i32>, player2: Vec<i32>) -> i32 {
        let score1 = count_scores(&player1);
        let score2 = count_scores(&player2);
        if score1 > score2 {
            1
        } else if score1 < score2 {
            2
        } else {
            0
        }
    }
}
fn count_scores(scores: &[i32]) -> i32 {
    let mut total = 0;
    let mut double_time = 0;

    for &score in scores {
        total += score;
        if double_time > 0 {
            double_time -= 1;
            total += score;
        }

        if score == 10 {
            double_time = 2;
        }
    }
    total
}
// @leet end
