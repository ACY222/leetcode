// @leet start
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
class Solution {
    class SegmentTree {
    private:
        int n;
        vector<int> tree;

    public:
        SegmentTree(int n) {
            this->n = n;
            this->tree.assign(2 * n, 0);
        }

        void update(int idx, int val) {
            idx += n;

            // otherwise, we don't need to modify the tree
            if (tree[idx] != val) {
                tree[idx] = val;

                for (idx /= 2; idx > 0; idx /= 2) {
                    tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
                }
            }
        }

        int query(int x) {
            int res = 0;

            for (int left = n, right = x + n + 1; left < right;
                 left >>= 1, right >>= 1) {
                // ask parent whenever you can
                if ((left & 1) == 1) { res = max(res, tree[left++]); }
                if ((right & 1) == 1) { res = max(res, tree[--right]); }
            }

            return res;
        }
    };

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_idx = 0;
        for (const vector<int>& query : queries) {
            max_idx = max(max_idx, query[1]);
        }

        SegmentTree tree(max_idx + 1);
        set<int> obstacles {0};
        vector<bool> answer;
        answer.reserve(queries.size());

        for (const vector<int>& query : queries) {
            if (query[0] == 1) {
                int obs = query[1];

                auto it = obstacles.insert(obs).first;
                // update previous obstacle
                tree.update(obs, obs - *prev(it));
                // update next obstracle if it exists
                if (next(it) != obstacles.end()) {
                    tree.update(*next(it), *next(it) - obs);
                }
            } else {
                int x = query[1], size = query[2];

                int tree_gap = tree.query(x);
                auto it = obstacles.upper_bound(x);
                int end_gap = x - *prev(it);

                answer.push_back(size <= max(tree_gap, end_gap));
            }
        }
        return answer;
    }
};
// @leet end
