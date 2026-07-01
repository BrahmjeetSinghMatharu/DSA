class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int count = 0;
        for(char c : word){
            if(isupper(c)) count++;
        }

        return count == 0 || count == n || (count == 1 && isupper(word[0]));
    }
};