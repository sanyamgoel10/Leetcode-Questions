class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        vector<int> xDir = {-1,+1,0,0};
        vector<int> yDir = {0,0,-1,+1};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int neighborWaters = 0;
                    for(int t=0;t<4;t++){
                        int currRow = i + xDir[t];
                        int currCol = j + yDir[t];
                        if(currRow<0 || currCol<0 || currRow>=m || currCol>=n || grid[currRow][currCol]==0){
                            neighborWaters++;
                        }                        
                    }
                    ans += neighborWaters;
                }
            }
        }
        return ans;
    }
};