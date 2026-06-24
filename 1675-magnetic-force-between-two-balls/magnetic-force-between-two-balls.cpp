class Solution {
public:
    bool canPlace(vector<int>& position, int m, int dis){
        int n = position.size();
        int cnt = 1;
        int pos = 0;
        for(int i=1;i<n;i++){
            if(position[i]-position[pos] >= dis){
                cnt++;
                pos = i;
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();

        int low = 1;
        int high = position[n-1] - position[0];
        int ans = 1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(canPlace(position,m,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};