class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;
        int ans = 0;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                ans = mid;
                break;
            }
            if(arr[mid] < arr[mid+1]) left = mid+1;
            else right = mid;
        }
        return ans;
    }
};