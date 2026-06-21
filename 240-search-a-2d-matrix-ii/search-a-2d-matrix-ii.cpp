class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        int r = 0;
        int c = column-1;

        while(r<row && c>=0){
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) r=r+1;
            else c = c-1;
        }
        return false;
    }
};