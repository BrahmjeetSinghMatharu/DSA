class Solution {
public:
    void solve(int index,int target,vector<int> &ds,vector<vector<int>> &ans,vector<int>& candidates){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        if(target < 0) return;

        for(int i=index;i<candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            if(target-candidates[i] < 0) break;

            ds.push_back(candidates[i]);
            solve(i+1,target-candidates[i],ds,ans,candidates);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,ds,ans,candidates);
        return ans;
    }
};