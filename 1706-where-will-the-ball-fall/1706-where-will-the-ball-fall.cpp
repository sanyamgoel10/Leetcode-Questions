class Solution {
    int solve(int row, int col, vector<vector<int>>& grid, int& m, int& n, vector<vector<int>>& dp){
        if((col==0 && grid[row][col]==-1) || (col==n-1 && grid[row][col]==1)){
            return -1;
        }
        if((grid[row][col]==1 && grid[row][col+1]==-1) || (grid[row][col]==-1 && grid[row][col-1]==1)){
            return -1;
        }
        if(row==m-1){
            if(grid[row][col]==1){
                return col+1;
            }
            else{
                return col-1;
            }
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        
        if(grid[row][col]==1 && grid[row][col+1]==1){
            return dp[row][col]=solve(row+1,col+1,grid,m,n,dp);
        }
        else{
            return dp[row][col]=solve(row+1,col-1,grid,m,n,dp);
        }
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> ans(n, -1);
        
        // 1 -> left to right
        // -1 -> right to left
        
        for(int i=0;i<n;i++){
            vector<vector<int>> dp(m,vector<int>(n,-1));
            ans[i] = solve(0,i,grid,m,n,dp);
        }
        
        return ans;
    }
};