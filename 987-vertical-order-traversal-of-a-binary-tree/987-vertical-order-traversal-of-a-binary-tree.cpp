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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        map<int, map<int, multiset<int>>> hmap;
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();
                
                hmap[col][row].insert(curr->val);
                
                if(curr->left){
                    q.push({curr->left, {row+1, col-1}});
                }
                if(curr->right){
                    q.push({curr->right, {row+1, col+1}});
                }
            }
        }
        
        for(auto x : hmap){
            vector<int> temp;
            for(auto y : x.second){
                temp.insert(temp.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};