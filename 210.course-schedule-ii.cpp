// @leet start
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;
using std::unordered_map, std::queue, std::unordered_set;
class Solution {
  using intToSet = unordered_map<int, unordered_set<int>>;
private:
  intToSet findPreCourses(vector<vector<int>>& prerequisites, int num) {
    // map from courses to their prerequisites
    intToSet map;
    for (auto& edge : prerequisites) {
      int from = edge[1], to = edge[0];
      map[to].insert(from);
    }
    return map;
  }

  // return a queue whose elements are the courses without prerequisites
  queue<int> findNoPreCourses(intToSet& map, int num) {
    queue<int> q {};
    for (int i = 0; i < num; ++i) {
      if (!map.count(i)) {
        q.push(i);
      }
    }
    return q;
  }

  vector<int> topoSort(int num, intToSet& courseToPre, queue<int>& coursesWithoutPre) {
    vector<int> sortedCourses;
    while (!coursesWithoutPre.empty()) {
      // if the num of pre is decreased to 0, remove it from the map
      vector<int> coursesToRemove;
      int courseToLearn = coursesWithoutPre.front(); coursesWithoutPre.pop();
      sortedCourses.push_back(courseToLearn);
      for (auto& course : courseToPre) {
        // if courseToLearn is one of the prerequisites of current course
        // erase it
        if (course.second.count(courseToLearn)) {
          course.second.erase(courseToLearn);
          if (course.second.empty()) {
            coursesWithoutPre.push(course.first);
            coursesToRemove.push_back(course.first);   // remove it later
          }
        }
      }
      // remove the courses without prerequisites
      for (int& course : coursesToRemove) {
        courseToPre.erase(course);
      }
      coursesToRemove.clear();
    }
    if (sortedCourses.size() == num) {
      return sortedCourses;
    }
    return {};
  }
public:
  // topological sorting works
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    intToSet courseToPre {findPreCourses(prerequisites, numCourses)};
    queue<int> coursesWithoutPre {findNoPreCourses(courseToPre, numCourses)};
    return topoSort(numCourses, courseToPre, coursesWithoutPre);
  }
};
// @leet end
