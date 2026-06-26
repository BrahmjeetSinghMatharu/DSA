class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int result = 0;

        auto checkPalindrome = [&](int left,int right){
            while(left>=0 && right<n && s[left] == s[right]){
                result++;
                left--;
                right++;
            }
        };

        for(int i=0;i<n;i++){
            checkPalindrome(i,i);
            checkPalindrome(i,i+1);
        }
        return result;
    }
};