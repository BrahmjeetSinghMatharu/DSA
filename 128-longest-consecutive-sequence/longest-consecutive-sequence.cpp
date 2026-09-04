class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        int length = 1;
        unordered_set<int> s(nums.begin(),nums.end());

        for(int ele : s){
            if(s.find(ele-1) != s.end()) continue;
            int curr = 1;
            while(s.find(ele+curr) != s.end()) curr++;
            length = max(length,curr);
        }
        return length;
    }
};