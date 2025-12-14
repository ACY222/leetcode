// @leet start
#include <unordered_map>
#include <vector>


using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // record the frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& it : freq) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> res;
        res.reserve(k);
        for (int i = buckets.size() - 1; i >= 0 and res.size() < k; --i) {
            for (int num : buckets[i]) {
                res.push_back(num);
            }
        }
        return res;
    }
};
// @leet end
