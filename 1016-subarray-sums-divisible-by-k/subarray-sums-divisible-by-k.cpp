class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int n = nums.size();
        int prefixSum = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            int target = ((prefixSum % k) + k) % k;
            if(mpp.contains(target)){
                count += mpp[target];
            }
            mpp[target]++;
        }
        return count;
    }
};