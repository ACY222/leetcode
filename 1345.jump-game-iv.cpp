// @leet start
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    // from i to
    // i - 1 or i + 1, or j if arr[i] == arr[j]
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) { return 0; }

        int step = 0;
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> val_to_indices;
        for (int i = 0; i < n; ++i) {
            val_to_indices[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int curr_idx = q.front();
                int curr_val = arr[curr_idx];
                q.pop();

                if (curr_idx == n - 1) { return step; }

                if (visited[curr_idx]) { continue; }

                visited[curr_idx] = true;

                if (curr_idx - 1 > 0 and !visited[curr_idx - 1]) {
                    q.push(curr_idx - 1);
                }

                if (curr_idx + 1 < n and !visited[curr_idx + 1]) {
                    q.push(curr_idx + 1);
                }

                for (int next_idx : val_to_indices[curr_val]) {
                    if (!visited[next_idx]) { q.push(next_idx); }
                }

                val_to_indices.erase(curr_val);
            }

            ++step;
        }

        return -1;
    }
};
// @leet end
