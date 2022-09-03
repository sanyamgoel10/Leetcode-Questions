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
    TreeNode* arrToBST(int i, int j, vector<int>& nums){
        if(i>j){
            return NULL;
        }
        int mid = (i+j)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = arrToBST(i, mid-1, nums);
        root->right = arrToBST(mid+1, j, nums);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = arrToBST(0, nums.size()-1, nums);
        return root;
    }
};