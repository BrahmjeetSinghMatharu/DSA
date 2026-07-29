class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int top = st2.top();
            st2.pop();
            return top;
        }
        else{
            while(!st1.empty()){
                int t = st1.top();
                st1.pop();
                st2.push(t);
            }
            int s = st2.top();
            st2.pop();
            return s;
        }
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        else{
            while(!st1.empty()){
                int t = st1.top();
                st1.pop();
                st2.push(t);
            }
            return st2.top();
        }
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
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