class Solution {
public:
    bool canEat(vector<int>& piles, int speed,int h){
        long long time = 0;
        for(int x : piles){
            time += (x+speed-1)/speed;
        }
        return time <= h ? true : false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;

        for(int x : piles){
            right = max(right,x);
        }

        int ans = right;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(canEat(piles,mid,h)){
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