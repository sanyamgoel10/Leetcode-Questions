class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        
        int ans = 0;
        
        for(int i=1;i<n;i++){
            if(colors[i] == colors[i-1]){
                int minCost = min(neededTime[i-1], neededTime[i]);
                ans += minCost;
                neededTime[i] = max(neededTime[i-1], neededTime[i]);
            }
        }
        
        return ans;
    }
};