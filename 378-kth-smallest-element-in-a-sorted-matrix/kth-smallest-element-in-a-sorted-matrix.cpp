class Solution {
public:

    int check(vector<vector<int>>& matrix, int n,int m,int mid){
        int rows = n-1;
        int columns = 0;
        int count = 0;
        while(rows >= 0 && columns < m){
            if(matrix[rows][columns] <= mid){
                count += rows+1;
                columns++;
            }
            else{
                rows--;
            }
        }
        return count;
    }


    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n-1][m-1];

        int res = -1;

        while(low<=high){
            int mid = (low+high)/2;

            int ans = check(matrix,n,m,mid);

            if(ans<k){
                low = mid+1;
            }
            else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};