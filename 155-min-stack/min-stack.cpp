class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() < mini) {
            mini = 2LL * mini - st.top();
        }
        st.pop();
    }

    int top() {
        if (st.top() >= mini)
            return st.top();
        return mini;
    }

    int getMin() {
        return mini;
    }
};