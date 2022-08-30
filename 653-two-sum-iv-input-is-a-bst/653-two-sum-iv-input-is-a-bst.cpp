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
class BSTiterator{
    stack<TreeNode*> st;
    // reverse = true -> previous
    // reverse = false -> next
    bool reverse = true;
    
    void pushInStack(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
public:
    BSTiterator(TreeNode* root, bool isReverse){
        reverse = isReverse;    //declare the direction here only
        pushInStack(root);
    }
    
    int next(){
        TreeNode* curr = st.top();
        st.pop();
        if(reverse){
            pushInStack(curr->left);
        }
        else{
            pushInStack(curr->right);
        }
        return curr->val;
    }   
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        //use the approach of bst iterator
        //here use bst iterator for both next and previous element
        //use next() to find next element for each element
        //use prev() to find previous element of each element
        //we may use a single bst iterator class to implement both next and prev
        //just use a flag variable for that
        
        if(root==NULL){
            return false;
        }
        
        BSTiterator l(root, false);     //iterate from last to first in bst
        BSTiterator r(root, true);      //iterate from first to last in bst
        
        int i = l.next();
        int j = r.next();
        
        bool flag = false;
        while(i<j){
            if(i+j == k){
                flag = true;
                break;
            }
            else if(i+j < k){
                i = l.next();
            }
            else{
                j = r.next();
            }
        }
        return flag;
    }
};