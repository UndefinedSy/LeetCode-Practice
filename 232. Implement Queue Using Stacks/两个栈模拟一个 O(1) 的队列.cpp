class MyQueue {
private:
    std::stack<int> InputStack_;
    std::stack<int> OutputStack_;

    void LoadInStackData()
    {
        while (!InputStack_.empty())
        {
            OutputStack_.push(InputStack_.top());
            InputStack_.pop();
        }
    }

public:    
    /** Push element x to the back of queue. */
    void push(int x)
    {
        InputStack_.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (OutputStack_.empty())
            LoadInStackData();
        int Res = OutputStack_.top();
        OutputStack_.pop();
        return Res;
    }
    
    /** Get the front element. */
    int peek()
    {
        if (OutputStack_.empty())
            LoadInStackData();
        return OutputStack_.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty()
    {
        return InputStack_.empty() && OutputStack_.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */