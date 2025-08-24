// @leet start
#include <queue>
#include <unordered_map>
#include <vector>
using std::vector;
using std::queue;
using std::unordered_map;
class Solution {
public:
  int minJumps(vector<int>& arr) {
    int step {0};
    vector<bool> visited(arr.size(), false);
    unordered_map<int, vector<int>> valueToIndex {};
    // find all the indices with the same value
    for (int i = 0; i < arr.size(); ++i) {
      valueToIndex[arr[i]].push_back(i);
    }
    queue<int> q({0});  // initialized with index 0
    visited[0] = true;
    while (!q.empty()) {
      int size { (int)q.size() };
      while (size > 0) {
        int pos { q.front() };
        q.pop();
        --size;
        // if we have reached the last index of the array
        if (pos == arr.size() - 1) {
          return step;
        }
        // if the index is legal and unvisited
        if (pos + 1 < arr.size() && visited[pos + 1] == false) {
          q.push(pos + 1);
          visited[pos + 1] = true;
        }
        if (pos - 1 > 0 && visited[pos - 1] == false) {
          q.push(pos - 1);
          visited[pos - 1] = true;
        }
        // for all the indices but pos with the same value
        // push into the vector
        for (int i = 0; i < valueToIndex[arr[pos]].size(); ++i) {
          if (visited[valueToIndex[arr[pos]][i]] == false) {
            q.push(valueToIndex[arr[pos]][i]);
            visited[valueToIndex[arr[pos]][i]] = true;
          }
        }
        // clear the map with the specified key so that we won't visit them in
        // the future
        valueToIndex[arr[pos]].clear();
      }
      ++step;
    }
    return step;
  }
};
// @leet end
