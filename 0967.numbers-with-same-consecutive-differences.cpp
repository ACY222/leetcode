// @leet start
#include <vector>
using namespace std;
class Solution {
private:
    vector<int> res;

    inline bool is_valid(int digit, int k) {
        return digit - k >= 0 or digit + k <= 9;
    }

    // what should I store in path? numbers or digits
    // if numbers,
    // if digits
    int convert_to_int(const vector<int>& path, int n) {
        int num = 0;
        for (int i = 0; i < n; ++i) {
            num = num * 10 + path[i];
        }
        return num;
    }
    void backtrack(vector<int>& path, int n, int k) {
        if (path.size() == n) {
            res.push_back(convert_to_int(path, n));
            return;
        }

        int last_digit = path.back();
        if (last_digit - k >= 0) {
            path.push_back(last_digit - k);
            backtrack(path, n, k);
            path.pop_back();
        }
        if (k != 0 and last_digit + k <= 9) {
            path.push_back(last_digit + k);
            backtrack(path, n, k);
            path.pop_back();
        }
    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> path;
        for (int i = 1; i <= 9; ++i) {
            if (is_valid(i, k)) {
                path.push_back(i);
                backtrack(path, n, k);
                path.pop_back();
            }
        }
        return res;
    }
};
// @leet end
