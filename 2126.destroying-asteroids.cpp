// @leet start
#include <cstdint>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int64_t Mass = static_cast<int64_t>(mass);
        priority_queue<int, vector<int>, greater<int>> left_asteroids;

        for (int asteroid : asteroids) {
            if (Mass >= asteroid) {
                Mass += asteroid;
            } else {
                left_asteroids.push(asteroid);
            }
        }

        while (!left_asteroids.empty()) {
            int asteroid = left_asteroids.top();
            left_asteroids.pop();

            if (Mass < asteroid) { return false; }

            Mass += asteroid;
        }

        return true;
    }
};
// @leet end
