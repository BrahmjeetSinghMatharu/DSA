class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n,1);

        // Left traversal
        int left = 1;

        for(int i=1;i<n;i++){
            left = left * nums[i-1];
            res[i] = left;
        }

        // Right traversal
        int right = 1;

        for(int i=n-2;i>=0;i--){
            right = right * nums[i+1];
            res[i] *= right;
        }

        return res;
    }
};