class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int r = it.second.first;
            int c = it.second.second;
            int diff = it.first; 

            if(r == n-1 && c == m-1) return diff;

            for(auto& dir : directions){
                int x = r + dir[0];
                int y = c + dir[1];

                if(x>=0 && x<n && y>=0 && y<m){
                    int newEffort = max(abs(heights[r][c] - heights[x][y]),diff);
                    
                    if(newEffort < dist[x][y]){
                        dist[x][y] = newEffort;
                        pq.push({newEffort,{x,y}});
                    }
                }
            }
        }
        return 0;
    }
};