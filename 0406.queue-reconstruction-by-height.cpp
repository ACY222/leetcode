// @leet start
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        ans.reserve(people.size());
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
        });

        for (auto& person : people) {
            ans.insert(ans.begin() + person[1], std::move(person));
        }
        return ans;
    }
};
// @leet end
//
// input:  (7, 0), (4, 4), (7, 1), (5, 0), (6, 1), (5, 2)
// sorted: (7, 0), (7, 1), (6, 1), (5, 0), (5, 2), (4, 4)
// output: (5, 0), (7, 0), (5, 2), (6, 1), (4, 4), (7, 1),
