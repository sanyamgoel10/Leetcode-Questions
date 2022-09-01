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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int n = q.size();
            int previMin = q.front().second;
            int mini, maxi;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front().first;
                int col = q.front().second - previMin;
                q.pop();
                
                if(i==n-1){
                    maxi = col;
                }
                if(i==0){
                    mini = col;
                }
                
                if(curr->left){
                    q.push({curr->left, (long)(long)2*col + 1});
                }
                if(curr->right){
                    q.push({curr->right, (long)(long)2*col + 2});
                }
            }
            ans = max(ans, maxi-mini+1);
        }
        
        return ans;
    }
};