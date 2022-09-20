class Solution {
    int solve(int n, vector<int>& dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += solve(i-1, dp)*solve(n-i, dp);
        }
        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        /*
        0 -> 1 (empty bst)
        1 -> 1
        2 -> 2 = 1x0 + 0x1
        3 -> 5 = 0x2 + 1x1 + 2x0
        
        fn -> f0xf(n-1) + f1xf(n-2) + f2xf(n-3) + ...... + f(n-3)xf2 + f(n-2)xf1 + f(n-1)xf0
        */
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};