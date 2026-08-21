class Solution {
public:
    typedef pair<long long, int> P;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // {distance, node}
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        const int mod = 1e9 + 7;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entry
            if (dis > dist[node])
                continue;

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                long long edgeWt = it.second;

                // Found a shorter path
                if (dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }

                // Found another shortest path
                else if (dis + edgeWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};