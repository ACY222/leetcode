// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if (words[startIndex] == target) { return 0; }

        int size = words.size(), count = 1;
        int left = (startIndex - 1 + size) % size,
            right = (startIndex + 1) % size;

        while (left != right) {
            if (words[left] == target or words[right] == target) {
                return count;
            }

            left = (left - 1 + size) % size;
            right = (right + 1) % size;
            ++count;
        }

        if (words[left] == target) { return count; }

        return -1;
    }
};
// @leet end
