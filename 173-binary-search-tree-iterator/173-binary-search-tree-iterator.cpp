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
    stack<TreeNode*> st;
    void pushInStack(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        //use a stack for this problem
        //initially push all elements to the left of root including root into the stack
        //for next() call, return the value of stack's topmost element ans pop from stack, also push all the elements to the right stack's top element in the stack
        //for hasNext call, check if stack is not empty
        
        pushInStack(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        int ans = curr->val;
        
        pushInStack(curr->right);
        
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */