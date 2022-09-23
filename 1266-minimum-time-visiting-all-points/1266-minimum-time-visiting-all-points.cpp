class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int ans = 0;
        
        for(int i=1;i<n;i++){
            int prevX = points[i-1][0];
            int prevY = points[i-1][1];
            int currX = points[i][0];
            int currY = points[i][1];
            
            ans += max(abs(currX-prevX), abs(currY-prevY));
        }
        
        return ans;
    }
};