// @leet start
#include <numeric>
#include <vector>
using namespace std;
class Solution {
private:
    struct UnionFind {
        vector<int> parent;

        UnionFind(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }

        int find(int x) {
            if (x == parent[x]) { return x; }

            return (parent[x] = find(parent[x]));
        }

        void unite(const vector<int>& nums, int x, int y) {
            int root_x = find(x);
            int root_y = find(y);

            if (root_x != root_y) {
                if (nums[root_x] >= nums[root_y]) {
                    parent[root_y] = root_x;
                } else {
                    parent[root_x] = root_y;
                }
            }
        }
    };

public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            if (uf.find(i) != i) { continue; }
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) { uf.unite(nums, i, j); }
            }
        }

        vector<int> result;
        result.reserve(n);
        for (int i = 0; i < n; ++i) {
            result.push_back(nums[uf.find(i)]);
        }

        return result;
    }
};
// @leet end
