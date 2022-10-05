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
    void solve(int currDepth, TreeNode* root, int& val, int& depth){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL && currDepth==depth-1){
            TreeNode* nodel = new TreeNode(val);
            TreeNode* noder = new TreeNode(val);
            root->left = nodel;
            root->right = noder;
            return;
        }
        
        if(currDepth == depth-1){
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;
            
            TreeNode* nodel = new TreeNode(val);
            root->left = nodel;
            nodel->left = tempLeft;
            
            TreeNode* noder = new TreeNode(val);
            root->right = noder;
            noder->right = tempRight;
        }
        
        solve(currDepth+1, root->left, val, depth);
        solve(currDepth+1, root->right, val, depth);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        int currDepth = 1;
        
        solve(currDepth, root, val, depth);
        
        return root;
    }
};