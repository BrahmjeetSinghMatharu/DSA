class Solution {
public:
    bool canMakeBouquet(vector<int>& bloomDay, int m, int k,int day){
        int count = 0;
        int b = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                count++;
                if(count == k){
                    b++;
                    count = 0;
                }
            }else{
                count = 0;
            }
        }
        return b >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)m * k > bloomDay.size()){
            return -1;
        }

        int low = INT_MAX;
        int high = INT_MIN;

        for(int x : bloomDay){
            low = min(low,x);
            high = max(high,x);
        }

        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(canMakeBouquet(bloomDay,m,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};