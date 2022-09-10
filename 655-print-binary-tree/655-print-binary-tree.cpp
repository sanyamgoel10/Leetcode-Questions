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
    int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return 1+max(l,r);
    }
    void fillMatrix(int l, int r, int row, int m, int n, TreeNode* root, vector<vector<string>>& ans){
        if(root==NULL){
            return;
        }
        if(row>m){
            return;
        }
        int mid = (l+r)/2;
        ans[row][mid] = to_string(root->val);
        fillMatrix(l, mid-1, row+1, m, n, root->left, ans);
        fillMatrix(mid+1, r, row+1, m, n, root->right, ans);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        //find the height of the tree
        //width of tree is 2^height - 1
        //create matrix of heightXwidth
        //take left and right
        //use divide and conquer technique to add elements to the matrix
        //at each step increase the row and go until last of tree reached
        
        int height = getHeight(root);
        int width = pow(2, height)-1;
        
        cout<<height<<" "<<width;
        
        vector<vector<string>> ans(height, vector<string>(width, ""));
        
        int l = 0;
        int r = width-1;
        
        fillMatrix(l, r, 0, height, width, root, ans);
        
        return ans;
    }
};