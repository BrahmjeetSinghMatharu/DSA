class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        unordered_map<char, int> mpp;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            while (mpp.count(s[right])) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }
                left++;
            }
            mpp[s[right]]++;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};