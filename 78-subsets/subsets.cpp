class Solution {
public:
    void generateSubsets(int index,vector<int> &subset,vector<vector<int>> &ans,vector<int> &nums){
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }

        // Include
        subset.push_back(nums[index]);
        generateSubsets(index+1,subset,ans,nums);

        // Exclude
        subset.pop_back();
        generateSubsets(index+1,subset,ans,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        generateSubsets(0,subset,ans,nums);
        return ans;
    }
};