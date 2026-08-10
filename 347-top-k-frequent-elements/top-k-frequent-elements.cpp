class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int digit : nums){
            mpp[digit]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto entry : mpp){
            pq.push({entry.second,entry.first});
        }

        vector<int> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};