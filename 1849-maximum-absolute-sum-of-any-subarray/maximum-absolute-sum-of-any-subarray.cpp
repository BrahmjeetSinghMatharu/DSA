class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_ans = INT_MIN;
        int min_ans = INT_MAX;
        int maxEnding = 0;
        int minEnding = 0;

        for(int i=0;i<n;i++){
            maxEnding = max(nums[i],nums[i]+maxEnding);
            max_ans = max(max_ans,maxEnding);

            minEnding = min(nums[i],nums[i]+minEnding);
            min_ans = min(min_ans,minEnding);
        }

        return max(max_ans,-min_ans);
    }
};