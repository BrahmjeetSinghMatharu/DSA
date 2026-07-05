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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;  //index of the first node of that level
            long long first,last;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                long long curr_id = q.front().second - mini;
                q.pop();

                if(i==0) first = curr_id;
                if(i==size-1) last = curr_id;

                if(node->left != NULL) q.push({node->left,curr_id*2+1});
                if(node->right != NULL) q.push({node->right,curr_id*2+2});
            }
            ans = max(ans,last-first+1);
        }
        return (int)ans;
    }
};