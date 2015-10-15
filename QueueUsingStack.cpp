//Original
class Queue {
public:
    deque<int> d;
    // Push element x to the back of queue.
    void push(int x) {
        d.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        d.pop_front();
    }

    // Get the front element.
    int peek(void) {
        return d.front();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return d.size() == 0;
    }
};

//Another
class Queue {
    stack<int> input, output;
public:

    void push(int x) {
        input.push(x);
    }

    void pop(void) {
        peek();
        output.pop();
    }

    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
};
