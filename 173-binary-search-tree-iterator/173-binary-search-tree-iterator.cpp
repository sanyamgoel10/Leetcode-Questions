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
class BSTIterator {
    vector<TreeNode*> inorder;
    int i = -1;
    void inorderTraversal(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorderTraversal(root->left);
        inorder.push_back(root);
        inorderTraversal(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    int next() {
        i++;
        return inorder[i]->val;
    }
    
    bool hasNext() {
        if(i==inorder.size()-1){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */