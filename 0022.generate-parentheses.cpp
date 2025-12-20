// @leet start
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    // number of left parenthesis to generate and close
    void generateNextParenthese(int n, int num_to_generate, int num_to_close, string& path, unordered_set<string>& res) {
        if (path.size() == 2 * n) {
            if (num_to_generate == 0 and num_to_close == 0) {
                res.insert(path);
                return;
            }
        }

        if (num_to_generate > 0) {
            path.push_back('(');
            generateNextParenthese(n, num_to_generate - 1, num_to_close + 1, path, res);
            path.pop_back();
        }

        // append ')' only when there are open brackets which are not closed
        if (num_to_close > 0) {
            path.push_back(')');
            generateNextParenthese(n, num_to_generate, num_to_close - 1, path, res);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> res;
        string path;
        generateNextParenthese(n, n, 0, path, res);
        return vector<string>(res.begin(), res.end());

    }
};
// @leet end
