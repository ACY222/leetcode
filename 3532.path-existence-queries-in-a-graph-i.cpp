// @leet start
#include <numeric>
#include <vector>
using namespace std;
class Solution {
    struct UnionFind {
        vector<int> parent;

        UnionFind(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }

        int find(int x) {
            if (parent[x] == x) return x;
            // no need to compress
            // because the depth of x won't be more than 2
            return find(parent[x]);
        }

        void unite(int x, int y) {
            int root_x = find(x), root_y = find(y);
            if (root_x != root_y) { parent[root_y] = parent[root_x]; }
        }

        bool is_connected(int x, int y) { return find(x) == find(y); }
    };

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        // diff(nums[i], nums[j]) <= maxDiff -> i <--> j
        UnionFind uf(n);
        int num_queries = queries.size();
        vector<bool> results;
        results.reserve(num_queries);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= maxDiff) { uf.unite(i, i + 1); }
        }

        for (auto& query : queries) {
            if (uf.is_connected(query[0], query[1])) {
                results.push_back(true);
            } else {
                results.push_back(false);
            }
        }

        return results;
    }
};
// @leet end
