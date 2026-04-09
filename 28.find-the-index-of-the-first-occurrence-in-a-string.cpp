// @leet start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    void get_next(vector<int>& next, const string& needle) {
        for (int i = 1, j = 0; i < needle.size(); ++i) {
            while (j > 0 and needle[i] != needle[j]) {
                j = next[j - 1];
            }

            if (needle[i] == needle[j]) { ++j; }

            next[i] = j;
        }
    }

    int kmp_match(vector<int>& next, const string& haystack,
                  const string& needle) {
        get_next(next, needle);

        int i {0}, j {0};
        while (i < haystack.size() and j < needle.size()) {
            if (haystack[i] == needle[j]) {
                ++i, ++j;
            } else {
                if (j > 0) {
                    j = next[j - 1];
                } else {
                    ++i;
                }
            }
        }

        if (j == needle.size()) {
            return i - j;
        } else {
            return -1;
        }
    }

public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size(), 0);
        return kmp_match(next, haystack, needle);
    }
};
// @leet end
