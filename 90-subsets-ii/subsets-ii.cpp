class Solution {
public:
    void generateSubsets(int index,vector<int> &subset,vector<vector<int>> &ans,vector<int> &nums){
        // save the current state
        ans.push_back(subset);

        // try next choices
        for(int i=index;i<nums.size();i++){
            // skip invalid choices
            if(i > index && nums[i] == nums[i-1]) continue;

            // choose 
            subset.push_back(nums[i]);

            // explore
            generateSubsets(i+1,subset,ans,nums);

            // undo
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());  // new line
        generateSubsets(0,subset,ans,nums);
        return ans;
    }
};