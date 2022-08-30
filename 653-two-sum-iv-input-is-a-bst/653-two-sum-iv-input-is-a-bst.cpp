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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        //find the inorder of BST
        //inorder of BST is always sorted
        //use two pointers to find elements with sum=k
        //if found, make flag as true
        //else, return flag as false
        
        vector<int> in;
        inorder(root, in);
        
        int l = 0;
        int r = in.size()-1;
        
        bool flag = false;
        while(l<r){
            int sum = in[l]+in[r];
            if(sum>k){
                r--;
            }
            else if(sum<k){
                l++;
            }
            else{
                flag = true;
                break;
            }
        }
        return flag;
    }
};