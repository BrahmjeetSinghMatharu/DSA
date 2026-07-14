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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx,unordered_map<int,int> &mpp){
        if(start > end) return NULL;

        int rootVal = preorder[idx];
        TreeNode* root = new TreeNode(rootVal);
        int i = mpp[rootVal];
        idx++;

        root->left = solve(preorder,inorder,start,i-1,idx,mpp);
        root->right = solve(preorder,inorder,i+1,end,idx,mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;     // node -> index
        int n = preorder.size();
        int idx = 0;

        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }

        return solve(preorder,inorder,0,n-1,idx,mpp);
    }
};