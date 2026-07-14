/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int start,int end,int &idx,unordered_map<int,int> &mpp){
        if(start > end) return NULL;

        int rootVal = postorder[idx];
        TreeNode* root = new TreeNode(rootVal);
        int i = mpp[rootVal];
        idx--;

        root->right = solve(inorder,postorder,i+1,end,idx,mpp);
        root->left = solve(inorder,postorder,start,i-1,idx,mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;     // node -> index
        int n = postorder.size();
        int idx = n-1;

        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }

        return solve(inorder,postorder,0,n-1,idx,mpp);
    }
};