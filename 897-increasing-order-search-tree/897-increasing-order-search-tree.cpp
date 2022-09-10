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
    TreeNode* flatten(TreeNode* root, TreeNode* parent){
        if(root==NULL){
            return parent;
            
        }
        TreeNode* temp = flatten(root->left, root);
        root->left = NULL;
        root->right = flatten(root->right, parent);
        
        return temp;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        return flatten(root, NULL);
    }
};