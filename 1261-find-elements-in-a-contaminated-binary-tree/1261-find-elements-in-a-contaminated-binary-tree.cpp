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
class FindElements {
    unordered_map<int,int> hmap;
    void preorder(TreeNode* root, int x){
        if(root==NULL){
            return;
        }
        hmap[x]++;
        root->val = x;
        preorder(root->left, (2*x)+1);
        preorder(root->right, (2*x)+2);
    }
public:
    FindElements(TreeNode* root) {
        preorder(root, 0);
    }
    
    bool find(int target) {
        return hmap.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */