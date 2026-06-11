class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int num : nums){
            total += num;
        }

        int left = 0;

        for(int i=0;i<n;i++){
            int right = total - left - nums[i];

            if(left == right) return i;
            else left += nums[i];
        }
        return -1;
    }
};