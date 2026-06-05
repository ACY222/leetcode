// @leet start
#include <string>
#include <utility>
using namespace std;
class Solution {
private:
    bool is_vowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }

    void reverse(string& s, int start, int end) {
        for (int i = 0; i < (end - start + 1) / 2; ++i) {
            swap(s[start + i], s[end - i]);
        }
    }

public:
    string reverseWords(string s) {
        int num_vowels = 0;

        int i = 0;
        for (; i < s.size() and s[i] != ' '; ++i) {
            if (is_vowel(s[i])) { ++num_vowels; }
        }

        int start = i + 1, end = start;
        while (end < s.size()) {
            int curr_num_vowels = 0;
            for (end = start; end < s.size() and s[end] != ' '; ++end) {
                if (is_vowel(s[end])) { ++curr_num_vowels; }
            }
            if (curr_num_vowels == num_vowels) { reverse(s, start, end - 1); }

            start = end + 1;
        }

        return s;
    }
};
// @leet end
