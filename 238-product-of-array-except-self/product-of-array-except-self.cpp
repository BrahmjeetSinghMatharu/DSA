class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n,0);

        // First Iteration from left to right (for storing the left sum)

        int leftProd = 1;
        res[0] = 1;

        for(int i=1;i<n;i++){
            leftProd = nums[i-1] * leftProd;
            res[i] = leftProd;
        }

        // Second Iteration from right to left (for storing the right sum)

        int rightProd = 1;

        for(int i=n-2;i>=0;i--){
            rightProd = nums[i+1] * rightProd;
            res[i] *= rightProd;
        }

        return res;
    }
};