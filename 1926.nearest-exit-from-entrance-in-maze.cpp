// @leet start
#include <queue>
#include <vector>
using namespace std;
class Solution {
private:
    int step = 0, m, n;

    static constexpr char MARK = '+';
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};


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

                for (int i = 0; i < 4; ++i) {
                    int row {curr.first + dx[i]}, col {curr.second + dy[i]};
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
