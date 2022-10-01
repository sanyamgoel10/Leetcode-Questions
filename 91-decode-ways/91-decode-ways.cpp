class Solution {
    int solve(int ind, string& s, int& n, vector<int>& dp){
        if(ind==n){
            //base case for last digit
            return 1;
        }
        if(s[ind]=='0'){
            //substring cannot start with 0
            return 0;
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        //case when s[ind] is in range 1-9
        int ans = solve(ind+1, s, n, dp);
        
        //case when 's[ind],s[ind+1]'' is in range 10-26
        //if s[ind]=='1' -> then next number s[ind+1] can be anything
        //if s[ind]=='2' -> then next number s[ind+1] can be in range 0-6 only
        if(ind<n-1 && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<'7'))){
            //move ahead by 2 digits i this case
            ans += solve(ind+2, s, n, dp);
        }
        
        return dp[ind] = ans;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n, -1);
        
        return solve(0, s, n, dp);
    }
};