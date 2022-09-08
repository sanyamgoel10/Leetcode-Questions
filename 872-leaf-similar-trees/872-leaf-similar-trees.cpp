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
    void preorder(TreeNode* root, vector<int>& ans){
        if(!root){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val);
        }
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> p1;
        vector<int> p2;
        
        preorder(root1, p1);
        preorder(root2, p2);
        
        return p1==p2;
    }
};