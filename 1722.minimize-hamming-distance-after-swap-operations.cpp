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
    };

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int distance = 0;
        UnionFind uf(n);
        for (auto& swap : allowedSwaps) {
            int i = swap[0], j = swap[1];
            uf.unite(i, j);
        }

        unordered_map<int, unordered_map<int, int>> component_counts;

        for (int i = 0; i < n; ++i) {
            component_counts[uf.find(i)][source[i]]++;
        }

        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            auto& counts = component_counts[root];
            if (counts.find(target[i]) != counts.end()
                and counts[target[i]] > 0) {
                counts[target[i]]--;
            } else {
                distance++;
            }
        }

        return distance;
    }
};
// @leet end
