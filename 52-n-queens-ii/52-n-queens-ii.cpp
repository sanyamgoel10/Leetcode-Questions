class Solution {
    bool isSafe(int row, int col, vector<vector<int>>& board, int n){
        int x = row;
        int y = col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        
        x = row;
        y = col;
        while(y>=0 && x>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        
        x = row;
        y = col;
        while(y>=0 && x<n){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        
        return true;
    }
    void solve(int col, int& ans, vector<vector<int>>& board, int n){
        if(col==n){
            ans++;
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(i, col, board, n)){
                board[i][col] = 1;
                solve(col+1, ans, board, n);
                board[i][col] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        //same as N-Queen 1 problem
        //just change the return condition there to add the count of solution
        //firat created a board of nXn size
        //recursively go to each column and try to put queen in each row for that column
        //check for isSafe to put queen on that row,col at every step
        
        int ans = 0;
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        solve(0, ans, board, n);
        
        return ans;
    }
};