class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            // Push opening brackets in stack
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char ele = st.top();
                st.pop();
                if((ch == ')' && ele == '(') || (ch == ']' && ele == '[') || (ch == '}' && ele == '{')){
                    continue;
                } 
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};