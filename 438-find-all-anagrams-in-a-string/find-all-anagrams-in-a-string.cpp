class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int n = s.length();
        int k = p.length();

        if(k>n) return res;

        vector<int> pCount(26,0);
        vector<int> sCount(26,0);

        for(char x : p){
            pCount[x - 'a']++;
        }

        // First Pass
        for(int i=0;i<k;i++){
            sCount[s[i] - 'a']++;
        }

        if(pCount == sCount) res.push_back(0);

        for(int i=k;i<n;i++){
            sCount[s[i] - 'a']++;   // Add next element
            sCount[s[i-k] - 'a']--;     // Remove previous element

            if(pCount == sCount) res.push_back(i-k+1);
        }
        return res;
    }
};