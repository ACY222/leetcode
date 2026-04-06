// @leet start
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;
class Solution {
public:
    // I, V, X, L,  C,  D,   M
    // 1  5 10 50 100 500 1000
    string intToRoman(int num) {
        string roman;
        auto curr_index{0};
        unordered_map<int, char> coins{{{1000, 'M'},
                                        {500, 'D'},
                                        {100, 'C'},
                                        {50, 'L'},
                                        {10, 'X'},
                                        {5, 'V'},
                                        {1, 'I'}}};

        auto curr_value{1};
        while (num > 0) {
            auto last{num % 10};
            string combined;

            if (last == 4) {
                roman += coins[curr_value * 5];
                roman += coins[curr_value];
            } else if (last == 9) {
                roman += coins[curr_value * 10];
                roman += coins[curr_value];
            } else {
                roman.append(last % 5, coins[curr_value]);
                if (last >= 5) { roman += coins[curr_value * 5]; }
            }

            num /= 10;
            curr_value *= 10;
        }

        for (auto i{0}; i < roman.size() / 2; ++i) {
            swap(roman[i], roman[roman.size() - 1 - i]);
        }

        return roman;
    }
};
// @leet end
