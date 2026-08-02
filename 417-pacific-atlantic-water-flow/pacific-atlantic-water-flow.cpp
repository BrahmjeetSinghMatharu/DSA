class Solution {
public:
    int rows,columns;

    void dfs(int row,int column,vector<vector<int>>& heights,vector<vector<bool>>& visited){
        if(row<0 || row>=rows || column<0 || column>=columns || visited[row][column]){
            return;
        }

        visited[row][column] = true;

        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        for(auto& dir : directions){
            int new_i = row + dir[0];
            int new_j = column + dir[1];

            if(new_i>=0 && new_i<rows && new_j>=0 && new_j<columns && !visited[new_i][new_j] && heights[new_i][new_j] >= heights[row][column]){
                dfs(new_i,new_j,heights,visited);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        columns = heights[0].size();

        vector<vector<bool>> pacific(rows,vector<bool> (columns,false));
        vector<vector<bool>> atlantic(rows,vector<bool> (columns,false));

        // Pacific ocean : left column
        for(int i=0;i<rows;i++){
            dfs(i,0,heights,pacific);
        }

        // Pacific ocean : top row
        for(int j=0;j<columns;j++){
            dfs(0,j,heights,pacific);
        }

        // Atlantic ocean : right column
        for(int i=0;i<rows;i++){
            dfs(i,columns-1,heights,atlantic);
        }

        // Atlantic ocean : bottom row
        for(int j=0;j<columns;j++){
            dfs(rows-1,j,heights,atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};