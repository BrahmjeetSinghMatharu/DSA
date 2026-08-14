class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis,vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = true;

        vector<vector<int>> directions = {{1, 0},{0, 1},{-1, 0},{0, -1}};

        for (auto& dir : directions) {
            int new_x = i + dir[0];
            int new_y = j + dir[1];

            if (new_x >= 0 && new_x < n &&
                new_y >= 0 && new_y < m &&
                !vis[new_x][new_y] &&
                grid[new_x][new_y] == '1') {

                dfs(new_x, new_y, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, vis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};