class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];

            if(mpp.contains(complement)){
                return {i,mpp[complement]};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};