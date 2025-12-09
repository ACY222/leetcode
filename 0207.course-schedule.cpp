#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        int count = 0;

        for (auto& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            adj[from].push_back(to);
            ++indegree[to];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ++count;

            for (auto child : adj[curr]) {
                --indegree[child];
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        return count == numCourses;
    }
};