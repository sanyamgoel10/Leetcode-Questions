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
    void solve(string temp, string& ans, TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){            
            ans = min(ans, char(root->val+'a')+temp);
            return;
        }
        
        solve(char(root->val+'a')+temp, ans, root->left);
        solve(char(root->val+'a')+temp, ans, root->right);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "~";   //lexicologically maximum string
        string temp = "";
        
        solve(temp, ans,root);
        
        return ans;
    }
};