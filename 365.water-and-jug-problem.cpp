// @leet start
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
using namespace std;
class Solution {
private:
    int capa1, capa2;
    unordered_set<string> visited;

    string convert_to_string(int x, int y) {
        return to_string(x) + '-' + to_string(y);
    }

    bool traverse(queue<pair<int, int>>& q, int x, int y, int target) {
        string xy = convert_to_string(x, y);
        if (visited.count(xy)) {
            return false;
        }
        if (x + y == target) {
            return true;
        }
        visited.insert(xy);
        q.emplace(x, y);
        return false;
    }

    bool bfs(int target) {
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visited.emplace(0, 0);

        bool fill1 = false, fill2 = false, empty1 = false, empty2 = false,
        pour1 = false, pour2 = false;
        while (!q.empty()) {
            auto [x, y] = q.front();    q.pop();
            fill1 = traverse(q, capa1, y, target);
            fill2 = traverse(q, x, capa2, target);
            empty1 = traverse(q, 0, y, target);
            empty2 = traverse(q, x, 0, target);
            pour1 = traverse(q, max(0, x - capa2 + y), min(y + x, capa2), target);
            pour2 = traverse(q, min(x + y, capa1), max(0, y - capa1 + x), target);
            if (fill1 or fill2 or empty1 or empty2 or pour1 or pour2) {
                return true;
            }
        }
        return false;
    }

public:
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) {
            return false;
        }
        this->capa1 = x;
        this->capa2 = y;
        return bfs(target);
    }
};
// @leet end
