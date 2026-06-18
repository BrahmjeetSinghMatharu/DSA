class Solution {
public:
    int kadane(vector<int>& nums,int flag){
        int n = nums.size();

        int max_ans = INT_MIN;
        int min_ans = INT_MAX;

        int maxEnding = 0;
        int minEnding = 0;

        for(int i=0;i<n;i++){
            maxEnding = max(maxEnding + nums[i],nums[i]);
            max_ans = max(max_ans,maxEnding);

            minEnding = min(minEnding + nums[i],nums[i]);
            min_ans = min(min_ans,minEnding); 
        }

        return (flag == 0) ? min_ans : max_ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int x : nums){
            total += x;
        }

        int normal = kadane(nums,1);
        int mini = kadane(nums,0);
        int circular = total - mini;

        if(normal > 0) return max(normal,circular);

        return normal;
    }
};