// @leet start
#include <queue>
using std::queue;
class MyStack {
public:
  MyStack() {
    q = new queue<int>;
  }

  void push(int x) {
    q->push(x);
  }

  int pop() {
    int top, n {(int)q->size()};
    for (int i = 1; i < n; ++i) {
      top = q->front();
      q->pop();
      q->push(top);
    }
    top = q->front();
    q->pop();
    return top;
  }

  int top() {
    int top {this->pop()};
    this->push(top);
    return top;
  }

  bool empty() {
    return q->empty();
  }
private:
  queue<int>* q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @leet end
