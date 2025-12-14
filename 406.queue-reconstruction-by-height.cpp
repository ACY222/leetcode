// @leet start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), comp);

        for (int i = 0; i < people.size(); ++i) {
            int offset = people[i][1];
            ans.insert(ans.begin() + offset, people[i]);
        }
        return ans;
    }
};
// @leet end
//
// input:  (7, 0), (4, 4), (7, 1), (5, 0), (6, 1), (5, 2)
// sorted: (7, 0), (7, 1), (6, 1), (5, 0), (5, 2), (4, 4)
// output: (5, 0), (7, 0), (5, 2), (6, 1), (4, 4), (7, 1),
