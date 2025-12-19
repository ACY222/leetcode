// @leet start
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<int>> map;     // from sorted string to indices
        for (int i = 0; i < strs.size(); ++i) {
            string str =  strs[i];
            sort(str.begin(), str.end());

            auto it = map.find(str);
            if (it == map.end()) {
                map[str] = {i};
            }
            else {
                it->second.push_back(i);
            }
        }

        res.reserve(map.size());
        for (auto& [str, indices] : map) {
            res.push_back({});
            for (auto index : indices) {
                res.back().push_back(strs[index]);
            }
        }
        return res;
    }
};
// @leet end
