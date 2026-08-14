class Solution {
public:
    void dfs(int& i,vector<bool>& vis,vector<vector<int>>& isConnected){
        vis[i] = true;

        for(int j=0;j<isConnected[i].size();j++){
            if(!vis[j] && isConnected[i][j] == 1) dfs(j,vis,isConnected);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);

        int provinces = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};