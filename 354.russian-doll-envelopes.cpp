// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {

    vector<int> poker_piles;

    void binary_search(int poker) {
        // [left, right], where right side is included
        int left = 0, right = poker_piles.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (poker_piles[mid] < poker) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (left == poker_piles.size()) {
            poker_piles.push_back(poker);
        }
        else {
            poker_piles[left] = poker;
        }
    }
public:
    // both width and height are greater->can fit into
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort the envelopes by width in increasing order
        // if width equals, then by height in decreasing order
        auto compare = [](vector<int> x, vector<int> y) -> bool {
            if (x[0] < y[0]) {
                return true;
            }
            else if (x[0] == y[0]) {
                if (x[1] > y[1]) {
                    return true;
                }
            }
            return false;
        };
        sort(envelopes.begin(), envelopes.end(), compare);

        int num_piles = 0;
        for (int i = 0; i < envelopes.size(); ++i) {
            int poker = envelopes[i][1];
            binary_search(poker);
        }
        return poker_piles.size();
    }
};
// @leet end
