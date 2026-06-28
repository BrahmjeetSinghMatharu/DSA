class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int cummulativeSum = 0;
        mpp[0] = 1;

        long long leftValidPoints = 0;
        long long result = 0;

        for(int j=0;j<n;j++){
            if(nums[j] == target){
                leftValidPoints += mpp[cummulativeSum];
                cummulativeSum += 1;
            }
            else{
                cummulativeSum -= 1;
                leftValidPoints -= mpp[cummulativeSum];
            }

            mpp[cummulativeSum] += 1; 
            result += leftValidPoints;
        }
        return result;
    }
};