class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.length();

        for(char ch : s){
            if(!st.empty() && ((st.top() == 'A' && ch == 'B' ) || (st.top() == 'C' && ch == 'D'))){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        return st.size();
    }
};