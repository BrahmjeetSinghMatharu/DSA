class Solution {
public:
    typedef pair<int,int> P;

    void dijkstra(int n, vector<vector<P>>& adj, vector<int>& dist, int src){
        priority_queue<P,vector<P>,greater<P>> pq;

        // {dist,node}
        pq.push({0,src});
        dist[src]=0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(dis+edgeWt < dist[adjNode]){
                    dist[adjNode] = dis+edgeWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
    }

    int findResultCity(int n,vector<vector<int>>& dist,int distanceThreshold){
        int resCity = -1;
        int minCity = INT_MAX;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }

            if(cnt<=minCity){
                minCity = cnt;
                resCity = i;
            }
        }
        return resCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        vector<vector<P>> adj(n);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }


        for(int i=0;i<n;i++){
            dijkstra(n,adj,dist[i],i);
        }

        return findResultCity(n,dist,distanceThreshold);
    }
};