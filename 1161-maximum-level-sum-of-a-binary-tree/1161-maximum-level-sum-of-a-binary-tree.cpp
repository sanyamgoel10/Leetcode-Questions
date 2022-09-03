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
    int maxLevelSum(TreeNode* root) {
        
        int lev = 1;
        int maxi = INT_MIN;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int currLevel = 0;
        while(!q.empty()){
            currLevel++;
            int n = q.size();
            int currSum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                currSum+=curr->val;
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(currSum > maxi){
                maxi = currSum;
                lev = currLevel;
            }
        }
        return lev;
    }
};