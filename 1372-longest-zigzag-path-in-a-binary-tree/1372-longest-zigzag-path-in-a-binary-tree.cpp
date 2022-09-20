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
    void solve(int pathCovered, bool dir, TreeNode* root, int& ans){
        if(root==NULL){
            return;
        }
        
        ans = max(ans, pathCovered);
        
        //came from left direction
        if(dir==0){
            solve(pathCovered+1, 1, root->left, ans);    //goto left of current node and add path
            solve(1, 0, root->right, ans);   //goto right of current node and start new path
        }
        //came from right direction
        else{
            solve(1, 1, root->left, ans);    //goto left of current node and start new path
            solve(pathCovered+1, 0, root->right, ans);   //goto right of current node and add path
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int ans = 0;
        
        // 0 -> go left
        // 1 -> go right
        solve(0, 0, root, ans);
        solve(0, 1, root, ans);
        
        return ans;
    }
};