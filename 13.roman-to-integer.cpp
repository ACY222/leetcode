// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        auto res{0};
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        auto curr_idx{0};
        for (auto [value, symbol] : valueSymbols) {

            while (true) {
                auto obj_pos{s.find(symbol, curr_idx)};

                if (obj_pos == string::npos or obj_pos != curr_idx) { break; }
                res += value;
                curr_idx += symbol.size();
            }
        }

        return res;
    }
};
// @leet end
