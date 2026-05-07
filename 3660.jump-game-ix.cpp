// @leet start
#include <algorithm>
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
        vector<int> pre_max(n), suf_min(n);
        pre_max[0] = nums[0];
        suf_min[n - 1] = nums[n - 1];

        for (int i = 1; i < n - 1; ++i) {
            pre_max[i] = max(nums[i], pre_max[i - 1]);
            suf_min[n - i - 1] = min(suf_min[n - i], nums[n - i - 1]);
        }

        UnionFind uf(n);

        for (int i = 0; i < n - 1; ++i) {
            // a cut occurs!
            if (pre_max[i] < suf_min[i + 1]) { continue; }
            // skip united num
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
