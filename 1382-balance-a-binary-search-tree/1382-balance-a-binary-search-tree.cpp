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
        if(!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    TreeNode* inorderToBST(int l, int r, vector<int>& inorderTraversal){
        if(r<l)
            return NULL;
        
        int mid = (l+r)/2;
        
        TreeNode* root = new TreeNode(inorderTraversal[mid]);
        
        root->left = inorderToBST(l,mid-1,inorderTraversal);
        root->right = inorderToBST(mid+1,r,inorderTraversal);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        //get the inorder of the current bst
        //inorder is always sorted
        //create a bst form that inorder by method of divide and conquer
        //always take the mid node and go to its left and right subtrees
        //TC -> O(n)
        //SC -> O(n)
        
        vector<int> in;
        inorder(root, in);
        
        return inorderToBST(0, in.size()-1, in);
    }
};