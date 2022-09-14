class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int i = n-1;
        int carry = 1;
        while(i>=0){
            digits[i] += carry;
            if(digits[i]>9){
                digits[i] = 0;
                carry = 1;
            }
            else{
                carry = 0;
            }
            i--;
        }
        
        if(carry == 1){
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};