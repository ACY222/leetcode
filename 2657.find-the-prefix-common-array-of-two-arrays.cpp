// @leet start
#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int8_t> freq(n, 0);
        vector<int> res(n, 0);

        freq[A[0] - 1]++;
        freq[B[0] - 1]++;
        if (A[0] == B[0]) { res[0] = 1; }

        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1];
            freq[A[i] - 1]++;
            freq[B[i] - 1]++;

            if (freq[A[i] - 1] == 2) { res[i]++; }
            if (B[i] != A[i] and freq[B[i] - 1] == 2) { res[i]++; }
        }

        return res;
    }
};
// @leet end
