class Solution {
public:
    unordered_map<int,int> mpp;

    int fib(int n) {
        if(n<2) return n;

        if(mpp.find(n) != mpp.end()) return mpp[n];

        return mpp[n] = fib(n-1) + fib(n-2);
    }
};