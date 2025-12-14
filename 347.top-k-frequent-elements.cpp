// @leet start
#include <queue>
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

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    // freq, num
        for (auto& it : freq) {
            pq.emplace(it.second, it.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        res.reserve(k);
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @leet end
