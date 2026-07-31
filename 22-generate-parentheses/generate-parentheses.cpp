class Solution {
public:
    void solve(string& s,vector<string>& ans,int open,int closed,int n){
        if(s.length() == n*2){
            ans.push_back(s);
            return;
        }

        if(open<n){
            s.push_back('(');
            solve(s,ans,open+1,closed,n);
            s.pop_back();
        }
        if(closed < open){
            s.push_back(')');
            solve(s,ans,open,closed+1,n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(s,ans,0,0,n);
        return ans;
    }
};