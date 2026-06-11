class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int n=nums.size();
        int count=0;
        int sum=0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            int target = sum-k;
            if(mpp.contains(target)){
                count += mpp[target];
            }
            mpp[sum] ++;
        }
        return count;
    }
};