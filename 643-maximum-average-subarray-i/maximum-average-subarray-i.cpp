class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        int n=nums.size();

        for(int i=0;i<k;i++){
            ans += nums[i];
        }

        int i=0;
        int j=k-1;
        double ans_max = ans;

        while(j<n-1){
            i++;
            j++;
            ans = ans - nums[i-1] + nums[j];
            ans_max = max(ans_max,ans);
        }
        return ans_max/k;
    }
};