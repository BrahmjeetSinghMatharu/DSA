class Solution {
public:
    int solve(int i,int n,vector<int>& dp,vector<int>& cost){
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp1(n,-1) , dp2(n,-1);
        int zero = solve(0,n,dp1,cost);
        int one = solve(1,n,dp2,cost);
        return min(zero,one);
    }
};