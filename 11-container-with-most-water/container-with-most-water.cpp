class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int area = 0;

        while(l<r){
            int length = min(height[r],height[l]);
            int width = abs(r-l);
            int area1 = length * width;
            area = max(area,area1);

            if(height[l] >= height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return area;
    }
};