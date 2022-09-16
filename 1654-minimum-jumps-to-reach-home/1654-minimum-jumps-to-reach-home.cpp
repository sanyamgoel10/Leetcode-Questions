class Solution {
    unordered_map<int,int> hmap;
       
    int solve(int ind, bool back, int a, int b, int x, vector<vector<int>>& dp){
        if(ind==x){
            return 0;
        }
        if(ind<0 || hmap.find(ind)!=hmap.end() || ind>6000 || back>=2){
            return 1e9;
        }
        if(dp[ind][back]!=-1){
            return dp[ind][back];
        }
        
        dp[ind][back] = 1 + solve(ind+a, 0, a, b, x, dp);
        
        if(!back){ //cannot go back twice consecutively
            dp[ind][back] = min(dp[ind][back], 1+solve(ind-b, 1, a, b, x, dp));
        }
        
        return dp[ind][back];
    }
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto x : forbidden){
            hmap[x] = 1;
        }
        
        vector<vector<int>> dp(6001, vector<int>(2, -1));
        int ans = solve(0, 0, a, b, x, dp);
        if(ans > 1e9){
            return -1;
        }
        return ans;
    }
};