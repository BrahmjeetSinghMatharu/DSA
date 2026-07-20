class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> st;

        for(int i=2*n-1;i>=0;i--){
            int num = i%n;

            while(!st.empty() && nums[num] >= nums[st.top()]){
                st.pop();
            }
            if(!st.empty() && i<n){
                res[i] = nums[st.top()];
            }
            st.push(num);
        }
        return res;
    }
};