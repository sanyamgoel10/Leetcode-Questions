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
    int solve(TreeNode* root, int& maxSum){
        if(root==NULL){
            return 0;
        }
        
        int leftTreeSum = max(0, solve(root->left, maxSum));
        int rightTreeSum = max(0, solve(root->right, maxSum));
        
        int currSum = root->val + leftTreeSum + rightTreeSum;
        
        maxSum = max(maxSum, currSum);
        
        return max(leftTreeSum, rightTreeSum)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int maxSum = INT_MIN;
        
        solve(root, maxSum);
        
        return maxSum;
    }
};