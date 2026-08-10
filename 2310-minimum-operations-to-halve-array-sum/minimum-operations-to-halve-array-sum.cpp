class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        double total = 0;
        priority_queue<double> pq;

        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            total += nums[i];
        }

        double required = total/2;
        int cnt = 0;

        while(total > required){
            double ele = pq.top() / 2;
            pq.pop();

            total -= ele;
            pq.push(ele);
            cnt++;
        }
        return cnt;
    }
};