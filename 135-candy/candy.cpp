class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n,1);

        // left to right
        for(int i=1;i<n;i++){
            if(ratings[i-1] < ratings[i]){
                count[i] = count[i-1]+1;
            }
        }

        // right to left
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1] < ratings[i]){
                count[i] = max(count[i],count[i+1]+1);
            }
        }

        // final answer
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += count[i];
        }
        return ans;
    }
};