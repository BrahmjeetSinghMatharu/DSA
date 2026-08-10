class Solution {
public:
    struct compare{
        bool operator()(const pair<int,char>& a,const pair<int,char>& b){
            if(a.first != b.first){
                return a.first < b.first;   // largest frequency element at the top
            }
            return a.second > b.second;     // lexicographically smallest element
        }
    };

    string frequencySort(string s) {
        int n = s.length();

        unordered_map<char,int> mpp;
        for(char ch : s){
            mpp[ch]++;
        }

        priority_queue<pair<int,char>,vector<pair<int,char>>,compare> pq;

        for(auto entry : mpp){
            pq.push({entry.second,entry.first});
        }

        string ans = "";

        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            for(int i=0;i<freq;i++){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};