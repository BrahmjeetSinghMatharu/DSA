class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i=1;
        int candy = n;

        while(i<n){
            
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // Increasing slope - peak
            int peak = 0;
            while(ratings[i-1] < ratings[i]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }

            // Decreasing slope - dip
            int dip = 0;
            while(i<n && ratings[i-1] > ratings[i]){
                dip++;
                candy += dip;
                i++;
            }
            candy -= min(peak,dip);
        }
        return candy;
    }
};