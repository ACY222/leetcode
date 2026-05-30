// @leet start
#include <map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    // query 1 = [1, x] -> place an obstacle at x
    // query 2 = [2, x, sz] -> want to place a block in [0, x] with size sz
    vector<bool> getResults(vector<vector<int>>& queries) {
        map<int, int> blocks {{0, 0}};
        vector<bool> ans;
        for (const vector<int>& query : queries) {
            if (query[0] == 1) {
                int x = query[1];
                auto next = blocks.upper_bound(x);

                // largest x
                if (next == blocks.end()) {
                    blocks.emplace(x, x - blocks.rbegin()->first);
                    continue;
                }

                next->second = next->first - x;

                auto prev = --next;
                blocks.emplace(x, x - prev->first);
            } else {
                int x = query[1], size = query[2];
                if (x < size) {
                    ans.push_back(false);
                    continue;
                }

                bool can_place = false;

                auto it = blocks.begin();
                while (it != blocks.end() and it->first < x) {
                    if (it->second >= size) {
                        can_place = true;
                        break;
                    }
                    ++it;
                }

                if (can_place == false) {
                    --it;
                    can_place = (x - it->first) >= size;
                }

                ans.push_back(can_place);
            }
        }

        return ans;
    }
};
// @leet end
