class Solution {
public:
    void dfs(int row,int column,vector<vector<char>>& grid){
        int rows = grid.size();
        int columns = grid[0].size();

        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

        if(row<0 || row>=rows || column<0 || column>=columns || grid[row][column] == '0' ){
            return;
        }

        grid[row][column] = '0';

        for(auto& dir : directions){
            int new_i = row + dir[0];
            int new_j = column + dir[1];

            dfs(new_i,new_j,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int rows = grid.size();
        int columns = grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j] == '1'){
                    island++;
                    dfs(i,j,grid);
                }
            }
        }
        return island;
    }
};