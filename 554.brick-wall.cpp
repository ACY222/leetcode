// @leet start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int width = 0, depth = wall.size();
        for (auto brick : wall[0]) {
            width += brick;
        }

        if (width == 1) { return depth; }
        vector<int> num_edges(width - 1);

        for (int i = 0; i < depth; ++i) {
            int curr = -1;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                curr += wall[i][j];
                num_edges[curr]++;
            }
        }

        return depth - *std::max_element(num_edges.begin(), num_edges.end());
    }
};
// @leet end
// int main() {
//     // vector<vector<int>> wall {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2},
//     //                           {2, 4},       {3, 1, 2}, {1, 3, 1, 1}};
//     vector<vector<int>> wall {{1}, {1}, {1}};
//     Solution sol;
//     std::cout << sol.leastBricks(wall) << '\n';
// }
