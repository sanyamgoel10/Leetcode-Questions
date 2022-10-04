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
    void solve(string& temp, int& ans, TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            temp += (root->val + '0');
            ans += stoi(temp);
            temp.pop_back();
            return;
        }
        
        temp += (root->val + '0');
        
        solve(temp, ans, root->left);
        solve(temp, ans, root->right);
        
        temp.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        string temp = "";
        solve(temp, ans,root);
        
        return ans;
    }
};