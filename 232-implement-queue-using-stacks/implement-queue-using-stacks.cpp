class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            int top = st1.top();
            st1.pop();
            st2.push(top);
        }
        st1.push(x);

        while(!st2.empty()){
            int top = st2.top();
            st1.push(top);
            st2.pop();
        }
    }
    
    int pop() {
        int v = st1.top();
        st1.pop();
        return v;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
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