class Solution {
    bool solve(int i, int j, int k, vector<vector<char>>& board, string& word, int m, int n){
        if(k==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[k]){
            return false;
        }
        
        char curr = board[i][j];    //current character on board
        board[i][j] = ' ';  //mark current node as NULL on the board (visited)
        
        bool ans = solve(i-1,j,k+1,board,word,m,n) || solve(i+1,j,k+1,board,word,m,n) || solve(i,j-1,k+1,board,word,m,n) || solve(i,j+1,k+1,board,word,m,n); //all neighbors
        
        board[i][j] = curr; //backtrack
        
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(i, j, 0, board, word, m, n)){
                    return true;
                }
            }
        }
        return false;
    }
};