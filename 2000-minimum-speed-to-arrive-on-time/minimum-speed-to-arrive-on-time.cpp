class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int x){
        double time = 0;
        int n = dist.size();
        for(int i=0;i<n-1;i++){
            time += (dist[i]+x-1)/x;
        }
        time += (double)dist[n-1]/x;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        
        int ans = -1;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(isPossible(dist,hour,mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};