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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = true;   //true->goright,false->goleft
        
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                if(flag == true){
                    temp[i] = curr->val;
                }
                else{
                    temp[n-i-1] = curr->val;
                }
            }
            flag = !flag;
            ans.push_back(temp);
        }
        
        return ans;
    }
};