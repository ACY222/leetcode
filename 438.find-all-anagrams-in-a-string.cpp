// @leet start
#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }

        array<int, 26> freq_s {}, freq_p {};
        vector<int> res;

        // initialize the characters frequence for p and s
        for (int i = 0; i < p.size(); ++i) {
            ++freq_s[s[i] - 'a'];
            ++freq_p[p[i] - 'a'];
        }
        if (freq_s == freq_p) {
            res.push_back(0);
        }

        for (int i = p.size(); i < s.size(); ++i) {
            --freq_s[s[i - p.size()] - 'a'];
            ++freq_s[s[i] - 'a'];
            if (freq_s == freq_p) {
                res.push_back(i - p.size() + 1);
            }
        }
        return res;
    }
};
// @leet end
