// @leet start
struct TreeAncestor {
    // dp[i][j]: 2^j-th ancestor of node i, = -1 if not exists
    // we know that dp[i][2j] is the j-th ancestor of dp[i][j]
    dp: Vec<Vec<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TreeAncestor {
    fn new(n: i32, parent: Vec<i32>) -> Self {
        let n = n as usize;
        // ceil(log2(n))
        let max_log = (64 - n.leading_zeros()) as usize;
        let mut dp = vec![vec![-1; max_log]; n as usize];
        // initialize first ancestor
        for i in 0..n {
            dp[i][0] = parent[i];
        }

        // dp[i][j] = dp[dp[i][j - 1]][j - 1]
        for j in 1..max_log {
            for i in 0..n {
                let intermediate = dp[i][j - 1];
                if intermediate != -1 {
                    dp[i][j] = dp[dp[i][j - 1] as usize][j - 1];
                }
            }
        }

        TreeAncestor { dp }
    }

    fn get_kth_ancestor(&self, node: i32, k: i32) -> i32 {
        let mut j = 0;
        let mut k = k;
        let mut node = node;
        while k > 0 {
            if (k & 1) == 1 {
                node = self.dp[node as usize][j];
                if node == -1 {
                    return -1;
                }
            }

            k >>= 1;
            j += 1;
        }

        node
    }
}
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * let obj = TreeAncestor::new(n, parent);
 * let ret_1: i32 = obj.get_kth_ancestor(node, k);
 */
// @leet end
