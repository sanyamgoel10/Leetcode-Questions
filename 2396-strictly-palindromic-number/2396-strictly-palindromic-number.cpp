class Solution {
    
    bool solve(int n, int base){
        string ans = "";
        
        while(n!=0){
            int quotient = n/base;
            int rem = n%base;
            
            ans += to_string(rem);
            n = quotient;
        }
        
        //checking if the resultant string is a palindrome or not
        int l = 0;
        int r = ans.size()-1;
        while(l<r){
            if(ans[l]!=ans[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
public:
    bool isStrictlyPalindromic(int n) {
        //Steps to convert decimal to any other base :-
        // 1 - Divide the decimal number to be converted by the value of the new base.
        // 2 - Get the remainder from Step 1 as the rightmost digit (least significant digit) of new base number.
        // 3 - Divide the quotient of the previous divide by the new base.
        // 4 - Record the remainder from Step 3 as the next digit (to the left) of the new base number.
        
        for(int i=2;i<=n-2;i++){
            if(!solve(n, i)){
                return false;
            }
        }
        
        return true;
    }
};