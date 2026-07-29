class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        if(n<2) return s;

        stack<char> st;

        for(char ch : s){
            if(!st.empty() && abs(st.top() - ch) == 32){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        
        string res = "";

        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());

        return res;
    }
};