class Solution {
public:
    int subtractProductAndSum(int n) {
        double sum = 0;
        double product = 1;

        while(n > 0){
            double dig = n%10;
            product *= dig;
            sum += dig;
            n = n/10;
        }
        return product-sum;
    }
};