class Solution {
public:
    long long sumAndMultiply(int n) {
        int p = 1;
        int x = 0, s = 0;

        while (n > 0) {
            int d = n % 10;
            s += d;
            if (d != 0) {
                x += d * p;
                p *= 10;
            }
            n /= 10;
        }
        return 1LL * x * s;
    }
};