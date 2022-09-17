class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        //take two parameters ind and k
        //ind for iterating over array
        //k for checking the condition
        //run a loop from ind to find every subarray's average
        
        int n = nums.size();
        
        vector<vector<double>> dp(n+1, vector<double>(k+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0] = INT_MIN;
        }
        
        for(int t=1; t<=k; t++){
            for(int ind=0;ind<n;ind++){
                double ans = INT_MIN;
                double currSum = 0;
                for(int i=ind;i<n;i++){
                    currSum += nums[i];
                    double currAvg = currSum / (i-ind+1);
                    ans = max(ans, currAvg + dp[i+1][t-1]);
                }
                dp[ind][t] = ans;
            }
        }
        
        return dp[0][k];
    }
};