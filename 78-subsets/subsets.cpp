class Solution {
public:
    void solve(int index,vector<int>& nums,vector<int>& subset,vector<vector<int>>& ans) {
        // save the current state
        ans.push_back(subset);

        // try next choices
        for(int i=index;i<nums.size();i++){
            // choose
            subset.push_back(nums[i]);

            // explore
            solve(i+1,nums,subset,ans);

            // undo
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, nums, subset, ans);

        return ans;
    }
};