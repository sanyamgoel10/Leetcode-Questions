class Solution {
    int solve(int i, int j, int ind, vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& dp){
        if(ind==multipliers.size()){
            return 0;
        }
        if(dp[i][ind]!=INT_MIN){
            return dp[i][ind];
        }
        
        int start = (multipliers[ind]*nums[i]) + solve(i+1, j, ind+1, nums, multipliers, dp);
        int end = (multipliers[ind]*nums[(j-1)-(ind-i)]) + solve(i, j, ind+1, nums, multipliers, dp);
        
        return dp[i][ind] = max(start, end);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        
        vector<vector<int>> dp(1001, vector<int>(1001, INT_MIN));
        
        return solve(0, n, 0, nums, multipliers, dp);
    }
};