class Solution {
public:
    void solve(int index,string curr,string digits,vector<string>& ans,vector<string>& mapping){
        if(index == digits.length()){
            ans.push_back(curr);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for(char ch : letters){
            curr.push_back(ch);
            solve(index+1,curr,digits,ans,mapping);
            curr.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string curr;

        solve(0,curr,digits,ans,mapping);

        return ans;
    }
};