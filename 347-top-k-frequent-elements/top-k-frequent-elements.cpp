class Solution {
public:
    typedef pair<int,int> P;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // {element,frequency}
        unordered_map<int,int> mpp;

        for(int digit : nums){
            mpp[digit]++;
        }
        
        priority_queue<P,vector<P>,greater<P>> pq;

        for(auto it : mpp){
            pq.push({it.second,it.first});

            if(pq.size()>k) pq.pop();
        }

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};