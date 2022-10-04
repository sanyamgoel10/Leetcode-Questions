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
    void solve(int& temp, int& ans, TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            temp *= 10;
            temp += root->val;
            ans += temp;
            temp /= 10;
            return;
        }
        
        temp *= 10;
        temp += root->val;
        
        solve(temp, ans, root->left);
        solve(temp, ans, root->right);
        
        temp /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int temp = 0;
        solve(temp, ans, root);
        
        return ans;
    }
};