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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;

        TreeNode* curr = root;

        while(curr != NULL){
            // Case 1 : no left exists
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            // Case 2 : when left exists
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                // Make the thread
                if(prev->right == NULL){
                    prev->right = curr;
                    res.push_back(curr->val);
                    curr = curr->left;
                }
                // Destroying the thread
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};