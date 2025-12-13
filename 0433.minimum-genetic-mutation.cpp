// @leet start
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
private:
    int step = 0, index, numVisted;
    vector<bool> visited;

    // find the index of endGene in the bank, if not in, return -1
    int findIndexOfEndGene(string& endGene, vector<string>& bank) {
        // find the index in reverse order
        for (int i = bank.size() - 1; i >= 0; --i) {
            if (endGene == bank[i]) {
                return i;
            }
        }
        return -1;
    }

    // if the gene is unvisited, check if we can mutate to it
    bool canMutate(string& curr, string& gene) {
        int diff = 0;
        for (int i = 0; i < 8; ++i) {
            if (curr[i] != gene[i]) {
                if (++diff >= 2) {
                    return false;
                }
            }
        }
        return diff == 1;
    }

    bool pushValidGene(queue<string>& q, string& curr, int index,
                       vector<string>& bank) {
        for (int i = 0; i < bank.size(); ++i) {
            if (visited[i]) {   // don't visit the same gene twice
                continue;
            }
            // if we can mutate to an unvisited gene
            if (canMutate(curr, bank[i])) {
                visited[i] = true;
                ++numVisted;
                if (i == index) {   // if the gene is the object
                    return true;
                }
                // otherwise, push the indices into the queue
                q.push(bank[i]);
            }
        }
        return false;
    }

    void bfs(string& start, int index, vector<string>& bank) {
        queue<string> q;
        q.push(start);

        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; --size) {
                string curr = q.front(); q.pop();
                // if we have found the path to end
                if (pushValidGene(q, curr, index, bank)) {
                    return;
                }
            }
        }
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) {
            return 0;
        }
        visited.resize(bank.size());
        index = findIndexOfEndGene(endGene, bank);
        // endGene is not in the bank, so we cannot mutate to it
        if (index == -1) {
            return -1;
        }
        bfs(startGene, index, bank);
        if (!visited[index]) {
            return -1;
        }
        return step;
    }
};
// @leet end
