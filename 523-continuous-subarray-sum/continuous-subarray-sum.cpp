class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            int rem = prefixSum % k;
            if(mpp.contains(rem)){
                if(i-mpp[rem] >= 2){
                    return true;
                }
            }
            else{
                mpp[rem] = i;
            }
        }
        return false;
    }
};