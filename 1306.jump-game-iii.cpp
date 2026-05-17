// @leet start
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            if (arr[curr] == 0) { return true; }
            visited[curr] = true;
            q.pop();

            int left = curr - arr[curr], right = curr + arr[curr];

            if (left >= 0 and !visited[left]) { q.push(left); }
            if (right < n and !visited[right]) { q.push(right); }
        }

        return false;
    }
};
// @leet end
