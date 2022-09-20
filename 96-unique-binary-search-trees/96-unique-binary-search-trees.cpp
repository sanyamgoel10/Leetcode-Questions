class Solution {
public:
    int numTrees(int n) {
        /*
        0 -> 1 (empty bst)
        1 -> 1
        2 -> 2 = 1x0 + 0x1
        3 -> 5 = 0x2 + 1x1 + 2x0
        
        fn -> f0xf(n-1) + f1xf(n-2) + f2xf(n-3) + ...... + f(n-3)xf2 + f(n-2)xf1 + f(n-1)xf0
        */
        
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int ind=2;ind<=n;ind++){
            for(int i=1;i<=ind;i++){
                dp[ind] += dp[i-1]*dp[ind-i];
            }
        }
        
        return dp[n];
    }
};