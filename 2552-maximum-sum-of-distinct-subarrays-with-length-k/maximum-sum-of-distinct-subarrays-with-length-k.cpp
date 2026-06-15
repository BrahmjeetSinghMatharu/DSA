class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long ans1 = 0;
        unordered_map<int, int> mpp;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            mpp[nums[i]]++;
            ans += nums[i];
        }

        if (mpp.size() == k)
            ans1 = ans;

        int i = 0;
        int j = k - 1;

        while (j < n - 1) {
            // remove outgoing element
            ans -= nums[i];
            mpp[nums[i]]--;
            if (mpp[nums[i]] == 0)
                mpp.erase(nums[i]);

            i++;
            j++;

            // add incoming element
            ans += nums[j];
            mpp[nums[j]]++;

            if (mpp.size() == k)
                ans1 = max(ans1, ans);
        }

        return ans1;
    }
};