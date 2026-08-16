class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        
    void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        for(auto& dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];

            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y] == 1){
                dfs(x,y,vis,grid);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        // Top & Bottom Boundary
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0,j,vis,grid);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                dfs(n-1,j,vis,grid);
            }
        }

        // Left & Right Boundary
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i,0,vis,grid);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i,m-1,vis,grid);
            }
        }

        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};