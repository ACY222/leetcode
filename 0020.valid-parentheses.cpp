// @leet start
#include <stack>
#include <string>
using std::string;
using std::stack;
class Solution {
public:
  bool isValid(string s) {
    stack<char> st {};
    for (char c : s) {
      if (c == '(' or c == '{' or c == '[') {
        st.push(c);
      }
      else {
        if (st.empty()) {
          return false;
        }
        char top {st.top()};
        if ((top == '(' and c != ')') or (top == '[' and c != ']') or (top == '{' and c != '}')) {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};
// @leet end
