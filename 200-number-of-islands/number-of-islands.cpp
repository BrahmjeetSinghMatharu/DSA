class Solution {
public:
    void bfs(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;

            vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

            for(auto& dir : directions){
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && !vis[new_x][new_y] && grid[new_x][new_y] == '1'){
                    q.push({new_x,new_y});
                    vis[new_x][new_y] = true;
                }

            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int islands = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i,j,vis,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};