class Solution {
    int solve(int prev, int curr, string& s, int& k, int& n, vector<vector<int>>& dp){
        if(curr>=n){
            return 0;
        }
        if(dp[prev][curr]!=-1){
            return dp[prev][curr];
        }
        
        int nottake = 0 + solve(prev, curr+1, s, k, n, dp);
        int take = 0;
        if(prev==0 || abs(s[curr]-prev)<=k){
            take = 1 + solve(s[curr], curr+1, s, k, n, dp);
        }
        
        return dp[prev][curr] = max(take, nottake);
    }
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        
        //in dp array, we take previous element of string as prev and not the previous element index to avoid any TLE (hence we also took dp array of size 150 for ASCII strings)
        vector<vector<int>> dp(150, vector<int>(n+1, -1));
        return solve(0, 0, s, k, n, dp);
    }
};