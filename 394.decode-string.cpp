// @leet start
#include <cctype>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        int k = 0;
        string currString = "";

        for (auto c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            }
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(currString);

                k = 0;
                currString = "";
            }
            else if (c == ']') {
                int repeatTimes = countStack.top();
                countStack.pop();
                string prevString = stringStack.top();
                stringStack.pop();

                // repeat current string for k times
                for (int i = 0; i < repeatTimes; ++i) {
                    prevString += currString;
                }
                currString = prevString;
            }
            else {  // c is [a-z]
                currString += c;
            }
        }
        return currString;
    }
};
// @leet end
