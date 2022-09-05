class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //use BFS approach to traverse to all neighbors of image[sr][sc]
        //if image[sr][sc]==color, do nothing and return
        //go to all neighbors of current row and change their color if their color is not color
        //use queue for this
        //also take care of boundary conditions of row and column
        
        int m = image.size();
        int n = image[0].size();
        
        if(image[sr][sc] == color){
            return image;
        }
        
        int currColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr,sc});
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            vector<int> xDir = {-1,+1,0,0};
            vector<int> yDir = {0,0,-1,+1};
            if(image[row][col] == currColor){
                image[row][col] = color;
                for(int i=0;i<4;i++){
                    int currRow = row+xDir[i];
                    int currCol = col+yDir[i];
                    if(currRow>=0 && currRow<m && currCol>=0 && currCol<n){
                        q.push({currRow, currCol});
                    }
                }
            }
        }
        return image;
    }
};