class Solution {
    int mod = 1e9 + 7;
    int solve(int n, int& k, int target, vector<vector<int>>& dp){
        if(n==0 || target<0){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans = (ans + solve(n-1, k, target-i, dp))%mod;
        }
        return dp[n][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        dp[0][0] = 1;
        
        for(int ind=1;ind<=n;ind++){
            for(int j=1;j<=target;j++){
                for(int i=1;i<=k;i++){
                    if(i<=j){
                        dp[ind][j] = (dp[ind][j] + dp[ind-1][j-i])%mod;
                    }
                    else{
                        dp[ind][j] = (dp[ind][j] + 0)%mod;
                    }
                }
            }
            
        }
        return dp[n][target];
    }
};