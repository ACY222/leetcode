// @leet start
#include <cctype>
#include <stack>
#include <string>
using std::string, std::stack;
class Solution {
public:
  // includes integers, operators, no brackets
  int calculate(string s) {
    stack<int> st {};
    int total = 0, num = 0, n = s.size();
    char currSign = '+';
    for (int i = 0; i <= n; ++ i) {
      char c = (i < n) ? s[i] : '+';
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
      }
      else if (c == ' ') {
        continue;
      }
      else {
        int lastNum;
        switch (currSign) {
          case '+': st.push(num);   break;
          case '-': st.push(-num);  break;
          case '*':
            lastNum = st.top(); st.pop();
            st.push(lastNum * num);
            break;
          case '/':
            lastNum = st.top();
            st.pop();
            st.push(lastNum / num);
            break;
        }
        currSign = c;
        num = 0;
      }
    }
    while (!st.empty()) {
      int top = st.top(); st.pop();
      total += top;
    }
    return total;
  }
};
// @leet end
