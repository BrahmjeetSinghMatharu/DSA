class Solution {
public:
    bool canPlace(int row,int col,vector<string>& board,int n){
        // left top diagonal
        int r1 = row;
        int c1 = col;
        while(r1 >= 0 && c1 >= 0){
            if(board[r1][c1] == 'Q') return false;
            r1--;
            c1--;
        }

        // left
        r1 = row;
        c1 = col;
        while(c1>=0){
            if(board[r1][c1] == 'Q') return false;
            c1--;
        }

        // left down diagonal
        r1 = row;
        c1 = col;
        while(r1<n && c1>=0){
            if(board[r1][c1] == 'Q') return false;
            r1++;
            c1--;
        }
        return true;
    }


    void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(canPlace(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');

        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};