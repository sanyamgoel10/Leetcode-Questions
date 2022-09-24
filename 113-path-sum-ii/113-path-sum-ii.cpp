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
    void solve(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& ans){
        if(root==NULL){
            return;
        }
        
        temp.push_back(root->val);
        targetSum -= root->val;
        
        if(root->left==NULL && root->right==NULL){
            if(targetSum == 0){
                ans.push_back(temp);
            }
        }
        else{
            solve(root->left, targetSum, temp, ans);
            solve(root->right, targetSum, temp, ans);
        }
        
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, targetSum, temp, ans);
        return ans;
    }
};