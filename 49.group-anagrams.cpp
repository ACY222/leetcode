// @leet start
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;     // from sorted string to indices

        for (const auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(map.size());

        for (auto& pair : map) {
            res.push_back(std::move(pair.second));
        }
        return res;
    }
};
// @leet end
