// @leet start
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        for (int start = 0; start < n - 1; ++start) {
            int max_height = 0, max_idx = -1;
            for (int curr = start; curr < n; ++curr) {
                if (heights[curr] > max_height) {
                    max_height = heights[curr];
                    max_idx = curr;
                }
            }

            swap(names[start], names[max_idx]);
            swap(heights[start], heights[max_idx]);
        }

        return names;
    }
};
// @leet end
