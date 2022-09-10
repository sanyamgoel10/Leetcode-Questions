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
    int deepestLeavesSum(TreeNode* root) {
        //use level order traversal
        //get sum of the last level
        
        queue<TreeNode*> q;
        q.push(root);
        
        int ans;
        while(!q.empty()){
            int n = q.size();
            int tempSum = 0;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                tempSum += curr->val;
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans = tempSum;
        }
        return ans;
    }
};