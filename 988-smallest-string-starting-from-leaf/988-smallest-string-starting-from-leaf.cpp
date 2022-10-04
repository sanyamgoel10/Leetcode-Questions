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
    void solve(string& temp, string& ans, TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            temp += (root->val + 'a');
            reverse(temp.begin(), temp.end());
            
            ans = min(ans, temp);
            cout<<temp<<" ";
            
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            return;
        }
        
        temp += (root->val + 'a');
        
        solve(temp, ans, root->left);
        solve(temp, ans, root->right);
        
        temp.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzz";
        string temp = "";
        
        solve(temp, ans,root);
        
        cout<<endl;
        return ans;
    }
};