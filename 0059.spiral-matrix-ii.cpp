// @leet start
#include <vector>
using std::vector;
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> m(n);
    int num {1};
    for (int i = 0; i < n; ++i) {
      m[i].resize(n);
    }
    for (int base = 0; base < (n + 1) / 2; ++base) {
      int i = 1, j = 0;
      while (j < n - 2 * base) {
        m[base][base + j] = num;
        ++num; ++j;
      }
      while (i < n - 2  *base) {
        m[base + i][-base + n - 1] = num;
        ++num; ++i;
      }
      if (2 * base != n - 1) {
        j = n - 1 - 2 * base - 1;
        while (j >= 0) {
          m[-base + n - 1][base + j] = num;
          ++num; --j;
        }
        i = n - 1 - 2 * base - 1;
        while (i > 0) {
          m[base + i][base] = num;
          ++num; --i;
        }
      }
    }
    return m;
  }
};
// @leet end
