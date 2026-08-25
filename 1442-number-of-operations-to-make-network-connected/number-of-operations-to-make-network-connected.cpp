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

    int makeConnected(int n, vector<vector<int>>& connections) {

        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        int countExtra = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(findParent(u) == findParent(v)){
                countExtra++;
            }
            else{
                unionSet(u,v);
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(parent[i] == i) cnt++;
        }

        int ans = cnt - 1;
        if(countExtra >= ans) return ans;

        return -1;
    }
};