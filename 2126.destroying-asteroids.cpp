// @leet start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int max = asteroids.back();

        for (int asteroid : asteroids) {
            if (mass < asteroid) { return false; }

            if (mass >= max - asteroid) { return true; }
            mass += asteroid;
        }

        return true;
    }
};
// @leet end
