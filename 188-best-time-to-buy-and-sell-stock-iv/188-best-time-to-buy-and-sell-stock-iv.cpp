class Solution {
    int solve(int ind, int canbuy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind==prices.size() || k==0){
            return 0;
        }
        if(dp[ind][canbuy][k]!=-1){
            return dp[ind][canbuy][k];
        }
        
        int profit;
        
        if(canbuy){
            int buyNow = -prices[ind] + solve(ind+1, 0, k, prices, dp);
            int dontBuyNow = 0 + solve(ind+1, 1, k, prices, dp);
            profit = max(buyNow, dontBuyNow);
        }
        else{
            int sellNow = prices[ind] + solve(ind+1, 1, k-1, prices, dp);
            int dontSellNow = 0 + solve(ind+1, 0, k, prices, dp);
            profit = max(sellNow, dontSellNow);
        }
        
        return dp[ind][canbuy][k]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve(0, 1, k, prices, dp);
    }
};