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
        
        int next = 0;
        int curr = 0;
        
        for(int ind=n-1;ind>=0;ind--){
            int ans = 0;
            for(int i=ind;i<n;i++){
                if(isPalindrome(ind,i,s)){
                    ans++;
                }
            }
            curr = ans + next;
            next = curr;
        }
        return next;
    }
};