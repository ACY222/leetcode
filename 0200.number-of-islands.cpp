#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<int> parent(m * n, -1);
        vector<int> rank(m * n, 0);

        auto find = [&](int i) {
            int root = i;
            while (parent[root] != root) {
                root = parent[root];
            }
            // 整条路径压缩
            while (i != root) {
                int next = parent[i];
                parent[i] = root;
                i = next;
            }
            return root;
        };

        auto unite = [&](int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                // 总是将 秩(rank) 小的树合并到 秩 大的树上
                // 即将矮树合并到高树上
                if (rank[root_i] < rank[root_j]) {
                    swap(root_i, root_j);
                }
                parent[root_j] = root_i;
                if (rank[root_i] == rank[root_j]) {
                    rank[root_i]++;
                }
                count--; // 合并成功，岛屿数量减一
            }
        };

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '0') {
                    continue;
                }
                int index = r * n + c;
                parent[index] = index;
                ++count;

                if (r > 0 and grid[r - 1][c] == '1') {
                    unite(index, index - n);
                }
                if (c > 0 and grid[r][c - 1] == '1') {
                    unite(index, index - 1);
                }
            }
        }
        return count;
    }
};