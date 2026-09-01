class Solution {
public:
    int solve(int i,vector<int>& dp,vector<int>& nums){
        if(i==0) return nums[0];
        if(i<0) return 0;

        // 3. Use
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + solve(i-2,dp,nums);
        int notPick = 0 + solve(i-1,dp,nums);

        // 2. Store
        return dp[i] = max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1,temp2;

        // 1. Declare
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        int x = temp1.size();
        int y = temp2.size();

        int first = solve(x-1,dp1,temp1);
        int last = solve(y-1,dp2,temp2);

        return max(first,last);
    }
};