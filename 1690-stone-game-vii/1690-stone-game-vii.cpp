class Solution {
    int solve(int i, int j, int profit, vector<int>& stones, vector<vector<int>>& dp){
        if(i>=j){
            return 0;
        }
        if(profit <= 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
            
        // both the player have two options either they can choose the first element
        // or they can choose the last element
        // they will choose that particular element which will give them the maximum                profit
        // as player A wants to maximize its profit
        // and player B wants to minimize the difference between them
        // hence both will choose the maximum value only
        int left = profit - stones[i] - solve(i+1, j, profit-stones[i], stones, dp);
        int right = profit - stones[j] - solve(i, j-1, profit-stones[j], stones, dp);  
        
        return dp[i][j] = max(left, right);
    }
public:
    int stoneGameVII(vector<int>& stones) {
        //think of it like Bob gets negative points and Alice gets 
        //positive points and the sum of Bob's and Alice's points 
        //equals the amount of points Alice will win by
        
        int n = stones.size();
        
        int profit=0;
        for(auto x : stones){
            profit+=x;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(0, n-1, profit, stones, dp);
    }
};