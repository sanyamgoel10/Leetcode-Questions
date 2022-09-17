class Solution {
    double solve(int ind, int k, vector<int>& nums, int n, vector<vector<double>>& dp){
        if(ind>=n){
            return 0;
        }
        if(k==0){
            return INT_MIN;
        }
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        
        double ans = INT_MIN;
        double currSum = 0;
        for(int i=ind;i<n;i++){
            currSum += nums[i];
            double currAvg = currSum / (i-ind+1);
            ans = max(ans, currAvg + solve(i+1, k-1, nums, n, dp));
        }
        return dp[ind][k]=ans;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        //take two parameters ind and k
        //ind for iterating over array
        //k for checking the condition
        //run a loop from ind to find every subarray's average
        
        int n = nums.size();
        
        vector<vector<double>> dp(n, vector<double>(k+1, -1));
        return solve(0, k, nums, n, dp);
    }
};