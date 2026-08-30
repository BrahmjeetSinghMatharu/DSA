class Solution {
public:
    int solve(vector<int>& v,int n){
        if(n<2) return n;

        // 3. Check
        if(v[n] != -1) return v[n];

        // 2. Store
        return v[n] = solve(v,n-1) + solve(v,n-2);
    }

    int fib(int n) {
        // 1. Declare
        vector<int> v(n+1,-1);
        return solve(v,n);
    }
};