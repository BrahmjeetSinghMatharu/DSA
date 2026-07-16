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
    TreeNode* findLastRightChild(TreeNode* root){
        while(root->right) root = root->right;
        return root;
    }

    TreeNode* nodeToDelete(TreeNode* root){
        // If any side is null
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        // If we have both sides : last node of left subtree -> attach right subtree
        TreeNode* rightSubtree = root->right;
        TreeNode* lastRight = findLastRightChild(root->left);
        lastRight->right = rightSubtree;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return nodeToDelete(root);

        TreeNode* curr = root;
        while(curr != NULL){
            // Go left
            if(curr->val > key){
                if(curr->left != NULL && curr->left->val == key){
                    curr->left = nodeToDelete(curr->left);
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
            // Go right
            else{
                if(curr->right != NULL && curr->right->val == key){
                    curr->right = nodeToDelete(curr->right);
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};