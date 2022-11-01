class Solution {
    int solve(int row, int col, vector<vector<int>>& grid, int& m, int& n){
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
        
        if(grid[row][col]==1 && grid[row][col+1]==1){
            return solve(row+1,col+1,grid,m,n);
        }
        else{
            return solve(row+1,col-1,grid,m,n);
        }
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> ans;
        
        // 1 -> left to right
        // -1 -> right to left
        
        for(int i=0;i<n;i++){
            ans.push_back(solve(0,i,grid,m,n));
        }
        
        return ans;
    }
};