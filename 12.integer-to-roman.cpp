// @leet start
#include <string>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    // I, V, X, L,  C,  D,   M
    // 1  5 10 50 100 500 1000
    string intToRoman(int num) {
        string roman;

        vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        for (const auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                roman += symbol;
                num -= value;
            }

            if (num == 0) { break; }
        }

        return roman;
    }
};
// @leet end
