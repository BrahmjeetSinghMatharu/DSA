class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int sum = 0;
        int max_ans = 0;

        for(int i=0;i<n;i++){
            sum += gain[i];
            max_ans = max(max_ans,sum);
        }
        return max_ans;
    }
};