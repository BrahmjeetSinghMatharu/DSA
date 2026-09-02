class Solution {
public:
    int solve(int i,int n,vector<int>& dp,vector<int>& cost){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int pickOne = cost[i] + solve(i+1,n,dp,cost);
        int pickTwo = cost[i] + solve(i+2,n,dp,cost);

        return dp[i] = min(pickOne,pickTwo);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp1(n,-1) , dp2(n,-1);
        int zero = solve(0,n,dp1,cost);
        int one = solve(1,n,dp2,cost);
        return min(zero,one);
    }
};