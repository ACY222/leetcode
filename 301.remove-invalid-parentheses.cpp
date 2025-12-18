// @leet start
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool is_valid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') ++count;
            else if (c == ')') --count;

            // we have more close bracket than open bracket, invalid
            if (count < 0) return false;

        }
        return count == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> valid_string;
        unordered_set<string> visited;
        bool found = false;
        queue<string> q;
        q.push(s);

        while (!q.empty()) {
            if (found) {
                break;
            }

            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                // if we have found a valid string, we do not need to generate next
                if (is_valid(curr)) {
                    valid_string.push_back(curr);
                    found = true;
                }

                if (found) continue;

                // generate next string by removing a bracket
                for (int i = 0; i < curr.size(); ++i) {
                    if (curr[i] != '(' and curr[i] != ')') {
                        continue;
                    }

                    string next = curr.substr(0, i) + curr.substr(i + 1);
                    // if we have visited the same string
                    if (visited.find(next) != visited.end()) {
                        continue;
                    }
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        return valid_string;
    }
};
// @leet end
