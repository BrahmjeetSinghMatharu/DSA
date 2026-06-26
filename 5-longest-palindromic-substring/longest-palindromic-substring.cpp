class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int length = 1;
        int start = 0;

        auto checkPalindrome = [&](int left,int right){
            while(left>=0 && right<n && s[left] == s[right]){
                if(right-left+1 > length){
                    start = left;
                    length = right-left+1;
                }
                left--;
                right++;
            }
        };

        for(int i=0;i<n;i++){
            checkPalindrome(i,i);
            checkPalindrome(i,i+1);
        }

        return s.substr(start,length);
    }
};