// @leet start
struct UnionFind {
    parent: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        UnionFind {
            parent: (0..n).collect(),
        }
    }

    fn find(&self, x: usize) -> usize {
        if self.parent[x] == x {
            return x;
        }

        self.find(self.parent[x])
    }

    fn unite(&mut self, x: usize, y: usize) {
        let px = self.find(x);
        let py = self.find(y);

        if px == py {
            return;
        }

        self.parent[py] = px;
    }

    fn is_connected(&self, x: usize, y: usize) -> bool {
        self.find(x) == self.find(y)
    }
}

impl Solution {
    pub fn path_existence_queries(
        n: i32,
        nums: Vec<i32>,
        max_diff: i32,
        queries: Vec<Vec<i32>>,
    ) -> Vec<bool> {
        let n = n as usize;
        let mut uf = UnionFind::new(n);
        for i in 0..n - 1 as usize {
            if nums[i + 1] - nums[i] <= max_diff {
                uf.unite(i, i + 1);
            }
        }

        let mut result = Vec::with_capacity(queries.len());
        for query in queries {
            if uf.is_connected(query[0] as usize, query[1] as usize) {
                result.push(true);
            } else {
                result.push(false);
            }
        }

        result
    }
}
// @leet end
