/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //DFS SOLUTION
        
        if(!root) 
            return NULL;
            
        auto L = root -> left;
        auto R = root -> right;
        auto N = root -> next;
            
        if(L) {
            L -> next = R;                                
            if(N){
                R -> next = N -> left;  
            }
            connect(L);                                    
            connect(R);                                
        }
        
        return root;
    }
};