// @leet start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        auto res{0};
        unordered_map<char, int> symbolToValue{
            {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
            {'X', 10},   {'V', 5},   {'I', 1}};

        for (auto i{0}; i < s.size() - 1; ++i) {
            if (symbolToValue[s[i]] < symbolToValue[s[i + 1]]) {
                res -= symbolToValue[s[i]];
            } else {
                res += symbolToValue[s[i]];
            }
        }

        res += symbolToValue[s.back()];

        return res;
    }
};
// @leet end
