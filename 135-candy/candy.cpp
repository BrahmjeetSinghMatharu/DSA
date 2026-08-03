class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> l2r(n,1);
        vector<int> r2l(n,1);

        // left to right
        for(int i=1;i<n;i++){
            if(ratings[i-1] < ratings[i]){
                l2r[i] = l2r[i-1]+1;
            }
        }

        // right to left
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1] < ratings[i]){
                r2l[i] = r2l[i+1]+1;
            }
        }

        // final answer
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(l2r[i],r2l[i]);
        }
        return ans;
    }
};