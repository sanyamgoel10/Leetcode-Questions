/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };n 
 */
class Solution {
    int preorder(TreeNode* root, int& maxi){
        int leftTree, rightTree;
        
        if(root->left){
            leftTree = preorder(root->left, maxi);
        }
        else{
            leftTree = 0;
        }
        if(root->right){
            rightTree = preorder(root->right, maxi);
        }
        else{
            rightTree = 0;
        }
        
        if(root->left && root->left->val==root->val){
            leftTree += 1;
        }
        else{
            leftTree = 0;
        }
        if(root->right && root->right->val==root->val){
            rightTree += 1;
        }
        else{
            rightTree = 0;
        }
        
        maxi = max(maxi, leftTree+rightTree);
        
        return max(leftTree, rightTree);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int maxi = 0;
        preorder(root, maxi);
        return maxi;
    }
};