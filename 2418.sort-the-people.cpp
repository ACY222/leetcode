// @leet start
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using std::vector, std::string;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 0);

        std::sort(indices.begin(), indices.end(),
                  [&heights](int i, int j) { return heights[i] > heights[j]; });

        vector<string> res;
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            res.push_back(names[indices[i]]);
        }

        return res;
    }
};
// @leet end
