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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;

        TreeNode* curr = root;

        while(curr != NULL){
            // Case 1 : When there is no left node
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            // Case 2 : When the left node is present
            else{
                TreeNode* leftChild = curr->left;

                while(leftChild->right != NULL){
                    leftChild = leftChild->right;
                }

                leftChild->right = curr;
                // We can delete the curr->left
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return res;
    }
};