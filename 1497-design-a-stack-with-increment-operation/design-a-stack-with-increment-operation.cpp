class CustomStack {
public:
    vector<int> st;
    int maxSize;
    int currSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        currSize = 0;
    }
    
    void push(int x) {
        if(currSize == maxSize) return;

        st.push_back(x);
        currSize++;
    }
    
    int pop() {
        if(currSize == 0) return -1; 
        currSize--;
        int top = st.back();
        st.pop_back();
        return top;
    }
    
    void increment(int k, int val) {
        int limit = min(k,currSize);

        for(int i=0;i<limit;i++){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */