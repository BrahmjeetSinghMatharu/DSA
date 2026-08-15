class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int i,int j,int& initial,int& color,vector<vector<bool>>& vis,vector<vector<int>>& ans){
        int n = ans.size();
        int m = ans[0].size();

        vis[i][j] = true;
        ans[i][j] = color;
        
        for(auto& dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];

            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && ans[x][y] == initial){
                dfs(x,y,initial,color,vis,ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int initial = image[sr][sc];

        dfs(sr,sc,initial,color,vis,ans);

        return ans;
    }
};