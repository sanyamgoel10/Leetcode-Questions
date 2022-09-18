class Solution {
    bool isPalindrome(int l, int r, string& s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int solve(int ind, string& s, int& n, vector<int>& dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int ans = 0;
        for(int i=ind;i<n;i++){
            if(isPalindrome(ind,i,s)){
                ans++;
            }
        }
        
        return dp[ind] = ans + solve(ind+1, s, n, dp);
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        vector<int> dp(n+1, -1);
        return solve(0, s, n, dp);
    }
};