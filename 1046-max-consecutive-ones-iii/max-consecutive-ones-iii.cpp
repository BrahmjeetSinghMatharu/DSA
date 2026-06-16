class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeros = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Include current element in window
            if (nums[right] == 0)
                zeros++;

            // Window invalid -> too many zeros
            while (zeros > k) {

                if (nums[left] == 0)
                    zeros--;

                left++;
            }

            // Current window is valid
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};