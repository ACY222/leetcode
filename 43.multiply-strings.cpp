// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        vector<int> res(size1 + size2);
        for (int i = size1 - 1; i >= 0; --i) {
            for (int j = size2 - 1; j >= 0; --j) {
                int prod = (num1[i] - '0') * (num2[j] - '0');

                int p1 = i + j;
                int p2 = i + j + 1;

                int eventual_prod = prod + res[p2];

                res[p2] = eventual_prod % 10;
                res[p1] += eventual_prod / 10;
            }
        }

        string result;
        for (auto digit : res) {
            if (result.empty() and digit == 0) { continue; }
            result.push_back(digit + '0');
        }

        return result.empty() ? "0" : result;
    }
};
// @leet end
