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
    TreeNode* first;
    TreeNode* second;
    TreeNode* third;
    TreeNode* prev;     //keeping track of previous element of root
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        
        if(root->val < prev->val){
            //1st violation
            if(first==NULL){
                first = prev;
                second = root;
            }
            //2nd violation
            else{
                third = root;
            }
        }
        prev = root;
        
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        
        first = second = third = NULL;
        prev = new TreeNode(INT_MIN);
        
        inorder(root);
        
        //only 1 violation occured
        //swap first and second
        if(third==NULL){
            swap(first->val, second->val);
        }
        //2 vilations occured
        //replace 1st and third
        else{
            swap(first->val, third->val);
        }
    }
};