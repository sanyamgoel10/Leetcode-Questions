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
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        vector<int> dp(n+1, 0);
        
        for(int ind=n-1;ind>=0;ind--){
            int ans = 0;
            for(int i=ind;i<n;i++){
                if(isPalindrome(ind,i,s)){
                    ans++;
                }
            }
            dp[ind] = ans + dp[ind+1];
        }
        return dp[0];
    }
};