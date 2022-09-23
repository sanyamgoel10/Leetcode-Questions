class Solution {
    long long mod = 1e9 + 7;
    
    int countbits(int n){
        //counts number of bits in the number n
        return log2(n)+1;
    }
    
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        
        for(int i=1;i<=n;i++){
            //left shift the answer by number of bits in the i'th number
            ans = (ans << countbits(i)^i) % mod;
        }
        
        return ans % mod;
    }
};