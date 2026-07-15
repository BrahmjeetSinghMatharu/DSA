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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode* curr = root;

        while(true){
            // Value to insert is greater than node : move right
            if(curr->val <= val){
                if(curr->right) curr = curr->right;     // Right node exists
                else{                                   // Right node does not exists
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            // Value to insert is less than node : move left
            else{
                if(curr->left) curr = curr->left;       // Left node exists
                else{                                   // Left node does not exists
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};