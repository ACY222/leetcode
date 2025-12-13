// @leet start
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    vector<bool> visited;
    int count = 0;
    void bfs(const vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        int curr;

        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (!visited[curr ]) {
                visited[curr] = true;
                ++count;
                if (count == rooms.size()) {
                    return;
                }
            }
            for (int key : rooms[curr]) {
                if (visited[key]) {
                    continue;
                }
                q.push(key);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size());
        bfs(rooms);
        return count == rooms.size();
    }
};
// @leet end
