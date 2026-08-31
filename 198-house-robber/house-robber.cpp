class Solution {
public:
    int solve(int i,vector<int>& dp, vector<int>& nums){
        if(i<0) return 0;
        if(i==0) return nums[0];

        // 3. Use
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + solve(i-2,dp,nums);
        int notPick = 0 + solve(i-1,dp,nums);

        // 2. Store
        return dp[i] = max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // 1. Declare
        vector<int> dp(n+1,-1);
        return solve(n-1,dp,nums);
    }
};