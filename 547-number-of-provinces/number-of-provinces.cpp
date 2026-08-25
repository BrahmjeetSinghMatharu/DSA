class Solution {
public:
    vector<int> parent,rank;

    int findParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionSet(int u,int v){
        u = findParent(u);
        v = findParent(v);

        if(u == v) return;

        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();

        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j] == 1){
                    unionSet(i,j);
                }
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            if(parent[i] == i){
                cnt++;
            }
        }
        return cnt;
    }
};