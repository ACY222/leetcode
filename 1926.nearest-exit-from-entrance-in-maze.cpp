// @leet start
#include <queue>
#include <vector>
using namespace std;
class Solution {
private:
    int step = 0, m, n;

    static constexpr char MARK = '+';
    const vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    inline bool isBorder(int row, int col) {
        return (row == 0 or row == m - 1 or col == 0 or col == n - 1);
    }

    inline bool outside(int row, int col) {
        return (row < 0 or row >= m or col < 0 or col >= n);
    }

    bool bfs(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = MARK;

        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; --size) {
                auto curr = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int row {curr.first + dir[0]}, col {curr.second + dir[1]};
                    if (outside(row, col) or maze[row][col] != '.') {
                        continue;
                    }
                    if (isBorder(row, col)) {
                        return true;
                    }
                    q.push({row, col});
                    maze[row][col] = MARK;
                }
            }
        }
        return false;
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        this->m = maze.size();  // m, n >= 1
        this->n = maze[0].size();
        if (bfs(maze, entrance)) {
            return step;
        }
        return -1;
    }
};
// @leet end
