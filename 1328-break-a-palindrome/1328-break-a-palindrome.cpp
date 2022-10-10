class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        int l = 0;
        
        while(l<n/2){
            if(palindrome[l]>'a'){
                palindrome[l] = 'a';
                return palindrome;
            }
            l++;
        }
        
        if(n>1){
            palindrome[n-1] = 'b';
            return palindrome;
        }
        
        
        // bool x = "aa"<"ab";
        // cout<<x;
        
        return "";
    }
};