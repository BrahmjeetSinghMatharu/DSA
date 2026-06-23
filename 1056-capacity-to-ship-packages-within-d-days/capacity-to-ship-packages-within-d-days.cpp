class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int time = 1;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            if(sum + weights[i] > capacity){
                time ++;
                sum = 0;
            }
            sum += weights[i];
        }
        return time <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN;
        int right = 0;

        for(int x : weights){
            left = max(left,x);
            right += x;
        }

        int ans = right;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(isPossible(weights,days,mid)){
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