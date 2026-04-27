// @leet start
#include <array>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
class Solution {
private:
    const array<vector<pair<int, int>>, 7> street_to_dirs = {{
        {},
        {{0, -1}, {0, 1}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {1, 0}},
        {{0, 1}, {1, 0}},
        {{0, -1}, {-1, 0}},
        {{0, 1}, {-1, 0}},
    }};

    struct UnionFind {
        vector<int> parent;

        UnionFind(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (x == parent[x]) { return x; }
            return (parent[x] = find(parent[x]));
        }

        void unite(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);
            if (root_x != root_y) { parent[root_x] = root_y; }
        }

        bool is_connected(int x, int y) { return find(x) == find(y); }
    };

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);

        auto get_id = [&n](int r, int c) { return r * n + c; };

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int type = grid[r][c];

                if (c + 1 < n) {
                    int next_type = grid[r][c + 1];
                    bool left_can_right = (type == 1 or type == 4 or type == 6);
                    bool right_can_left =
                        (next_type == 1 or next_type == 3 or next_type == 5);
                    if (left_can_right and right_can_left) {
                        uf.unite(get_id(r, c), get_id(r, c + 1));
                    }
                }

                if (r + 1 < m) {
                    int next_type = grid[r + 1][c];
                    bool up_can_down = (type == 2 or type == 3 or type == 4);
                    bool down_can_up =
                        (next_type == 2 or next_type == 5 or next_type == 6);

                    if (up_can_down and down_can_up) {
                        uf.unite(get_id(r, c), get_id(r + 1, c));
                    }
                }
            }
        }

        return uf.is_connected(get_id(0, 0), get_id(m - 1, n - 1));
    }
};
// @leet end
