class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // PERFORM BFS TRAVERSAL ON THE GRID STARTING FROM {0,0}
        
        //visited array
        //stores number of obstacles that we can still remove after going through that cell
        vector<vector<int>> vis(m,vector<int> (n, -1));
        
        //queue(for bfs) containing vector {i,j,l,k} -> {row,column,currentPathLength,obstaclesLeft}
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty()){
            vector<int> temp = q.front();
            int i = temp[0];    //current i
            int j = temp[1];    //current j
            q.pop();
            
            if(i<0 || j<0 || i>m-1 || j>n-1){
                continue;
            }
            
            if(i==m-1 && j==n-1){
                return temp[2];     //path found from {0,0} to {m-1,n-1}
            }
            
            if(grid[i][j]==1){
                if(temp[3]>0){
                    temp[3]--;
                }
                else{
                    continue;
                }
            }
            
            if(vis[i][j]!=-1 && vis[i][j] >= temp[3]){
                //node already visited
                //and, the solution would repeat itself
                //because number of nodes deleted earlier on this node from previous path were more
                continue;
            }
            vis[i][j] = temp[3];
            
            q.push({i, j-1, temp[2]+1, temp[3]}); // go left
            q.push({i-1, j, temp[2]+1, temp[3]}); // go up
            q.push({i, j+1, temp[2]+1, temp[3]}); // go right
            q.push({i+1, j, temp[2]+1, temp[3]}); // go down
        }
        
        return -1;  //didnt reach {0,0}
    }
};