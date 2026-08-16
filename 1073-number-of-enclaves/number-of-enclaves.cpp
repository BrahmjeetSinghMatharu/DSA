class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;

        // Top & Bottom Boundary
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                q.push({0,j});
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                q.push({n-1,j});
            }
        }

        // Left & Right Boundary
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                q.push({i,0});
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                q.push({i,m-1});
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vis[row][col] = true;

            for(auto& dir : directions){
                int x = row + dir[0];
                int y = col + dir[1];

                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y] == 1){
                    vis[x][y] = true;
                    q.push({x,y});
                }
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