class Solution {
public:
    int rows,columns;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int row,int column,vector<vector<char>>& board){
        if(row<0 || row>=rows || column<0 || column>=columns || board[row][column] != 'O'){
            return;
        }

        board[row][column] = '#';

        for(auto& dir : directions){
            int new_i = row + dir[0];
            int new_j = column + dir[1];
            
            dfs(new_i,new_j,board);
        }
    }


    void solve(vector<vector<char>>& board) {
        rows = board.size();
        columns = board[0].size();

        for(int i=0;i<rows;i++){
            // leftmost column
            if(board[i][0] == 'O'){
                dfs(i,0,board);
            }

            // rightmost column
            if(board[i][columns-1] == 'O'){
                dfs(i,columns-1,board);
            }
        }

        for(int j=0;j<columns;j++){
            // topmost row
            if(board[0][j] == 'O'){
                dfs(0,j,board);
            }

            // bottom row
            if(board[rows-1][j] == 'O'){
                dfs(rows-1,j,board);
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};