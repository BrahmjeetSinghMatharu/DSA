class Solution {
public:

    int largestArea(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i=0;i<=n;i++){
            int currHeight = (i==n) ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = (st.empty()) ? i : i - st.top() - 1;
                maxArea = max(maxArea,height*width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n,0);
        int maxArea = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea,largestArea(heights));
        }
        return maxArea;
    }
};