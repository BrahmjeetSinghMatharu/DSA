class Solution {
public:
    unordered_map<int,int> mpp;

    int fib(int n) {
        if(n<2) return n;

        if(mpp.find(n) != mpp.end()) return mpp[n];

        int res = fib(n-1) + fib(n-2);
        mpp[n] = res;

        return res;
    }
};