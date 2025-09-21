// @leet start
#include <queue>
#include <vector>
using namespace std;
class Solution {
private:
    int step = 0, m, n;

    static constexpr char MARK = '#';
    const vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    inline bool atBorder(int row, int col) {
        return (row == 0 or row == m - 1 or col == 0 or col == n - 1);
    }
    // if curr is not entrance and is on the border of the maze
    bool isExit(vector<int>& curr, vector<int>& entrance) {
        if (curr != entrance and atBorder(curr[0], curr[1])) {
            return true;
        }
        return false;
    }

    inline bool outside(int row, int col) {
        return (row < 0 or row >= m or col < 0 or col >= n);
    }

    void oneStepForward(queue<vector<int>>& q, vector<vector<char>>& maze,
                        vector<int>& curr) {
        for (auto& dir : dirs) {
            int row = curr[0] + dir[0], col = curr[1] + dir[1];
            // if it's not empty or it's outside, we won't move to it
            if (outside(row, col) or maze[row][col] != '.') {
                continue;
            }
            // if it's accessible, push it into the queue and mark it
            // so that we won't visit the position again
            q.push({row, col});
            maze[row][col] = MARK;
        }
    }

    bool bfs(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q;
        q.push(entrance);
        maze[entrance[0]][entrance[1]] = MARK;
        vector<int> curr;

        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                curr = q.front();
                q.pop();
                if (isExit(curr, entrance)) {
                    return true;
                }
                oneStepForward(q, maze, curr);
            }
            ++step;
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
