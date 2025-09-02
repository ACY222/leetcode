// @leet start
#include <stack>
using std::stack;
class MyQueue {
public:
  MyQueue() {
    s1 = new stack<int>;
    s2 = new stack<int>;
  }

  void push(int x) {
    s1->push(x);
  }

  int pop() {
    // if s2 is empty, pop all s1 into s2
    if (s2->empty()) {
      while (!s1->empty()) {
        s2->push(s1->top());
        s1->pop();
      }
    }
    int res {s2->top()};
    s2->pop();
    return res;
  }

  int peek() {    // same to top()
    if (s2->empty()) {
      while (!s1->empty()) {
        s2->push(s1->top());
        s1->pop();
      }
    }
    int res {s2->top()};
    return res;
  }

  bool empty() {
    if (s1->empty() && s2->empty()) {
      return true;
    }
    return false;
  }
private:
  stack<int>* s1;
  stack<int>* s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @leet end
