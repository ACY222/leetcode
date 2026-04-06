// @leet start
#include <string>
#include <unordered_map>
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
                combined += coins[curr_value];
                combined += coins[curr_value * 5];
            } else if (last == 9) {
                combined += coins[curr_value];
                combined += coins[curr_value * 10];
            } else {
                if (last >= 5) {
                    combined += coins[curr_value * 5];
                    last %= 5;
                }
                combined.append(last, coins[curr_value]);
            }

            roman.insert(0, combined);
            num /= 10;
            curr_value *= 10;
        }

        return roman;
    }
};
// @leet end
