class node{
    public:
    int data;
    int row;
    int col;

    node(int d,int i,int j){
        data = d;
        row = i;
        col = j;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        priority_queue<node*,vector<node*>,compare> pq;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            mini = min(mini,nums[i][0]);
            maxi = max(maxi,nums[i][0]);
            pq.push(new node(nums[i][0],i,0));
        }

        int start = mini;
        int end = maxi;

        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();

            mini = temp->data;

            // Update the answer
            if((maxi - mini) < (end-start)){
                end = maxi;
                start = mini;
            }

            // Insert next element
            if(temp->col + 1 < nums[temp->row].size()){
                maxi = max(maxi,nums[temp->row][temp->col+1]);
                pq.push(new node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else{
                break;
            }
            delete temp;
        }
        return {start,end};
    }
};