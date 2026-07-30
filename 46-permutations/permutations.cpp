class Solution {
public:
    void solve(vector<bool>& used,vector<int>& curr,vector<int>& nums,vector<vector<int>>& ans){
        // store the current state
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        // try new combinations
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;

            // choose
            curr.push_back(nums[i]);
            used[i] = true;

            // explore
            solve(used,curr,nums,ans);

            // undo
            used[i] = false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size());
        solve(used,curr,nums,ans);

        return ans;
    }
};