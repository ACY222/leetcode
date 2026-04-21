// @leet start
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
private:
    struct UnionFind {
        vector<int> parent;
        // parent[i] == i
        UnionFind(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }
        int find(int i) {
            if (parent[i] == i) return i;
            return (parent[i] = find(parent[i]));
        }

        void unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) { parent[root_i] = root_j; }
        }

        bool is_connected(int i, int j) { return find(i) == find(j); }
    };

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int dist = 0;
        UnionFind uf(n);
        for (auto pair : allowedSwaps) {
            int i = pair[0], j = pair[1];
            uf.unite(i, j);
        }

        unordered_map<int, unordered_map<int, int>> components;

        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            components[root][source[i]]++;
            components[root][target[i]]--;
        }

        for (auto& [root, component] : components) {
            for (auto [_val, count] : component) {
                if (count != 0) { dist += abs(count); }
            }
        }

        return dist / 2;
    }
};
// @leet end
// 	source =
// 	[41,37,51,100,25,33,90,49,65,87,11,18,15,18]
//
// 	target =
// 	[41,92,69,75,29,13,53,21,17,81,33,19,33,32]
//
// 	allowedSwaps =
// 	[[0,11],[5,9],[6,9],[5,7],[8,13],[4,8],[12,7],[8,2],[13,5],[0,7],[6,4],[8,9],[4,12],[6,1],[10,0],[10,2],[7,3],[11,10],[5,2],[11,1],[3,0],[8,5],[12,6],[2,1],[11,2],[4,9],[2,9],[10,6],[12,10],[4,13],[13,2],[11,9],[3,6],[0,4],[1,10],[5,11],[12,1],[10,4],[6,2],[10,7],[3,13],[4,5],[13,10],[4,7],[0,12],[9,10],[9,3],[0,5],[1,9],[5,10],[8,0],[12,11],[11,4],[7,9],[7,2],[13,9],[12,3],[8,6],[7,6],[8,12],[4,3],[7,13],[0,13],[2,0],[3,8],[8,1],[13,6],[1,4],[0,9],[2,3],[8,7],[4,2],[9,12]]
//
// Output
//
// 	 11
//
// Expected
//
// 	 12
