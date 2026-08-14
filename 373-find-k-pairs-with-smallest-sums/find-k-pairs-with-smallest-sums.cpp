class Solution {
public:
    typedef pair<int,pair<int,int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P,vector<P>,greater<P>> pq;

        int m = nums1.size();
        int n = nums2.size();

        set<pair<int,int>> vis;

        int sum = nums1[0] + nums2[0];
        vis.insert({0,0});
        pq.push({sum,{0,0}});

        vector<vector<int>> result;

        while(k-- && !pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i],nums2[j]});

            // Push (i,j+1) if possible
            if(j+1 < n && vis.find({i,j+1}) == vis.end()){
                pq.push({nums1[i] + nums2[j+1],{i,j+1}});
                vis.insert({i,j+1});
            }

            // Push (i+1,j) if possible
            if(i+1 < m && vis.find({i+1,j}) == vis.end()){
                pq.push({nums1[i+1] + nums2[j],{i+1,j}});
                vis.insert({i+1,j});
            }
        }
        return result;
    }
};