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
    bool preorder(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL){
            return true;
        }
        else if(l==NULL || r==NULL){
            return false;
        }
        else if(l->val != r->val){
            return false;
        }
        return preorder(l->left, r->right) && preorder(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        return preorder(left, right);
    }
};