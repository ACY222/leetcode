// @leet start
#include <algorithm>
#include <cstdint>
#include <vector>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int64_t curr_mass = static_cast<int64_t>(mass);

        for (int asteroid : asteroids) {
            if (curr_mass < asteroid) { return false; }

            curr_mass += asteroid;
        }

        return true;
    }
};
// @leet end
