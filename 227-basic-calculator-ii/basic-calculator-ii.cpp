class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        int num = 0;
        char op = '+';

        for(int i=0;i<n;i++){
            char ch = s[i];

            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }

            // if the element is an operator or last element
            if((!isdigit(ch) && ch != ' ') || i == n-1){
                if(op == '+'){
                    st.push(num);
                }
                else if(op == '-'){
                    st.push(-num);
                }
                else if(op == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top*num);
                }
                else if(op == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/num);
                }
                op = ch;
                num=0;
            }
        }

        int ans=0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};