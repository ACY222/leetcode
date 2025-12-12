// @leet start
#include <algorithm>
#include <stack>

using namespace std;

struct Node {
    int val;
    int min_val;

    Node(int val, int min_val) : val(val), min_val(min_val) {}
};

class MinStack {
private:
    stack<Node> st;
public:
    MinStack() {
        // do nothing?
    }

    void push(int val) {
        int min_val;
        if (st.empty()) {
            min_val = val;
        }
        else {
            min_val = min(val, st.top().min_val);
        }
        Node new_node(val, min_val);
        st.push(new_node);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().val;

    }

    int getMin() {
        return st.top().min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @leet end
