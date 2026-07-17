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
    void inorder(TreeNode* root,TreeNode* &first,TreeNode* &middle,TreeNode* &last,TreeNode* &prev){
        if(root == NULL) return;

        // Left
        inorder(root->left,first,middle,last,prev);

        // Value
        if(root->val < prev->val){
            // First violation
            if(first == NULL){
                first = prev;
                middle = root;
            }
            // Second violation
            else{
                last = root;
            }
        }

        prev = root;

        // Right
        inorder(root->right,first,middle,last,prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* last = NULL;
        TreeNode* prev = new TreeNode(INT_MIN);

        inorder(root,first,middle,last,prev);

        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};