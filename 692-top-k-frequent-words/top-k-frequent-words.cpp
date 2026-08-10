class Solution {
public:
    struct compare{
        bool operator()(const pair<int,string>& a,const pair<int,string>& b){
            if(a.first != b.first){
                return a.first < b.first;   // largest element at the top
            }
            return a.second > b.second;     // lexicographically smallest at first
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
        unordered_map<string,int> mpp;

        int n = words.size();

        for(string word : words){
            mpp[word]++;
        }

        for(auto entry : mpp){
            pq.push({entry.second,entry.first});
        }

        vector<string> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};