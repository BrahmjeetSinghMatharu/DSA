class Solution {
public:
    string stringBuilder(string &s){
        stack<char> st;
        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i] == '#'){
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
        }

        string res = "";
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        
        return res;
    }

    bool backspaceCompare(string s, string t) {
        return stringBuilder(s) == stringBuilder(t);
    }
};