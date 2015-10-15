//One
class Stack {
public:
    deque<int> d;
    // Push element x onto stack.
    void push(int x) {
        d.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        d.pop_back();
    }

    // Get the top element.
    int top() {
        return d.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return d.size() == 0;
    }
};

//Another
class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return input.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
