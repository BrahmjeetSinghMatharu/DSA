class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int n = s.length();
        int k = p.length();

        vector<int> pCount(26,0);

        for(char c : p){
            pCount[c - 'a']++;
        }

        for(int i=0;i<=n-k;i++){
            vector<int> sCount(26,0);

            for(int j=i;j<i+k;j++){
                sCount[s[j] - 'a']++;
            }

            if(pCount == sCount) res.push_back(i);
        }
        return res;
    }
};