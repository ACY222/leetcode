// @leet start
struct TreeAncestor {
    parent: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TreeAncestor {
    fn new(n: i32, parent: Vec<i32>) -> Self {
        TreeAncestor {
            parent: parent.clone(),
        }
    }

    fn get_kth_ancestor(&self, node: i32, k: i32) -> i32 {
        let mut k = k;
        let mut ancestor = node;
        while k > 0 {
            ancestor = self.parent[ancestor as usize];
            if ancestor == -1 {
                break;
            }
            k -= 1;
        }

        ancestor
    }
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * let obj = TreeAncestor::new(n, parent);
 * let ret_1: i32 = obj.get_kth_ancestor(node, k);
 */
// @leet end
