// @leet start
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        int curr = n;
        while (visited.find(curr) == visited.end()) {
            visited.insert(curr);

            int next = 0;
            while (curr > 0) {
                int last = curr % 10;
                next += last * last;
                curr /= 10;
            }

            if (next == 1) { return true; }

            curr = next;
        }
        return false;
    }
};
// @leet end
