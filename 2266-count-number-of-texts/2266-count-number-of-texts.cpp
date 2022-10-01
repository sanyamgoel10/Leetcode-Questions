class Solution {
    int MOD = 1e9 + 7;
    int solve(int ind, string& s, int& n, vector<int>& nums, vector<int>& dp){
        if(ind==n){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int ans = 0;
        
        int currKey = s[ind] - '0';
        int cnt = nums[currKey];    //number of times the current digit can repeat
        
        int i = ind;
        while(i<n && i<ind+cnt){
            if(s[i] == s[ind]){
                ans = (ans + solve(i+1, s, n, nums, dp)) % MOD;
            }
            else{
                break;
            }
            i++;
        }
        return dp[ind] = ans;
    }
public:
    int countTexts(string pressedKeys) {        
        int n = pressedKeys.size();
        
        //every index mapped to number of cases it can have
        vector<int> nums = {0,0,3,3,3,3,3,4,3,4};
        
        vector<int> dp(n, -1);
            
        return solve(0, pressedKeys, n, nums, dp);
    }
};