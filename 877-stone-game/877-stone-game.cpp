class Solution {
    int solve(int i, int j, bool alicePlays, vector<int>& piles, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(alicePlays){
            int left = piles[i] + solve(i+1, j, 0, piles, dp);
            int right = piles[j] + solve(i, j-1, 0, piles, dp);
            return dp[i][j] = max(left, right);
        }
        else{
            int left = -piles[i] + solve(i+1, j, 1, piles, dp);
            int right = -piles[j] + solve(i, j-1, 1, piles, dp);
            return dp[i][j] = max(left, right);
        }
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        //If it is Alice's Turn then -> find the max number of stones we can get by either consuming the first pile from the piles or by consuming the last pile.
        //If it is Bob's turn then -> find the min number of stones we can get by decreasing the amount of the Alex's score.
        //If resultant score is positive -> true, else -> false
        
        vector<vector<int>> dp(n, vector<int>(n,-1));        
        int ans = solve(0, n-1, 1, piles, dp);
        
        return ans > 0;
    }
};