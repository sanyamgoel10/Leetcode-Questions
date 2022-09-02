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
    int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return 1+max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        if(abs(leftH-rightH) <= 1){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else{
            return false;
        }
        return true;
    }
};