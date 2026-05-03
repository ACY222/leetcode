// @leet start
#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int64_t, int> edge_counts;
        int max_edges = 0;

        for (const auto& row : wall) {
            int64_t curr_width = 0;
            for (int i = 0; i < row.size() - 1; ++i) {
                curr_width += row[i];
                edge_counts[curr_width]++;

                max_edges = max(max_edges, edge_counts[curr_width]);
            }
        }

        return wall.size() - max_edges;
    }
};
// @leet end
