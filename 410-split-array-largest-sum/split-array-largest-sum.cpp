class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int target){
        int n = nums.size();
        int sum = nums[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(sum + nums[i] > target){
                count++;
                sum = 0;
            }
            sum += nums[i];
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high = 0;

        for(int x : nums){
            low = max(low,x);
            high += x;
        }

        int ans = high;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};