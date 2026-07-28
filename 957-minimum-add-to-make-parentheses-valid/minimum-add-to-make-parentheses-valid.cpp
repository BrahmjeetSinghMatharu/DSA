class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int closed = 0;

        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else{
                if(!st.empty()) st.pop();
                else closed++;
            }
        }
        return st.size() + closed;
    }
};